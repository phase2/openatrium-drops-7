/**
 * @file
 * Javascript for the drag/drop module from https://github.com/fatlinesofcode/ngDraggable.
 * Modified by mpotter:
 * 1) to deal with ensuring that clicking a draggable object doesnt actually
 *    drag it until it's been moved a bit.
 * 2) allow separate id's to be assigned to drag/drop elements to control which
 *    drag objects can be dropped over which drop objects
 */

(function ($) {

angular.module("ngDraggable", [])
  .directive('ngDrag', ['$rootScope', '$parse', '$timeout', function ($rootScope, $parse, $timeout) {
    return {
      restrict: 'A',
      link: function (scope, element, attrs) {
        scope.value = attrs.ngDrag;
        //  return;
        var offset,_mx,_my,_tx,_ty;
        var _hasTouch = ('ontouchstart' in document.documentElement);
        var _pressEvents = 'touchstart mousedown';
        var _moveEvents = 'touchmove mousemove';
        var _releaseEvents = 'touchend mouseup';

        var $document = $(document);
        var $window = $(window);
        var _data = null;

        var _dragEnabled = false;

        var _dragDown = false;

        var _pressTimer=null;

        var onDragSuccessCallback = $parse(attrs.ngDragSuccess) || null;

        var initialize = function () {
          element.attr('draggable', 'false'); // prevent native drag
          toggleListeners(true);
        };

        var toggleListeners = function (enable) {
          // remove listeners

          if (!enable)return;
          // add listeners.

          scope.$on('$destroy', onDestroy);
          attrs.$observe("ngDrag", onEnableChange);
          scope.$watch(attrs.ngDragData, onDragDataChange);
          scope.$watch(attrs.ngDragId, onDragIdChange);
          element.on(_pressEvents, onpress);
        };
        var onDestroy = function (enable) {
          toggleListeners(false);
        };
        var onDragDataChange = function (newVal, oldVal) {
          _data = newVal;
          _data.dragging = false;
        }
        var onDragIdChange = function (newVal, oldVal) {
          _data.dragid = newVal;
        }
        var onEnableChange = function (newVal, oldVal) {
          _dragEnabled=scope.$eval(newVal);

        }
        /*
         * When the element is clicked start the drag behaviour
         * On touch devices as a small delay so as not to prevent native window scrolling
         */
        var onpress = function(evt) {
          if (_data.editorEnabled) return;
          if(! _dragEnabled)return;


          if(_hasTouch){
            cancelPress();
            _pressTimer = setTimeout(function(){
              cancelPress();
              onstartpress(evt);
            },100);
            $document.on(_moveEvents, cancelPress);
            $document.on(_releaseEvents, cancelPress);
          }else{
            onstartpress(evt);
          }

        }
        var cancelPress = function() {
          _dragDown = false;
          clearTimeout(_pressTimer);
          $document.off(_moveEvents, cancelPress);
          $document.off(_releaseEvents, cancelPress);
          $document.off(_moveEvents, onmove);
        }
        var onstartpress = function(evt) {
          _dragDown = true;
          _data.dragging = false;
          _dragStartX = evt.pageX;
          _dragStartY = evt.pageY;
          $document.on(_moveEvents, onmove);
          $document.on(_releaseEvents, cancelPress);
        }
        var onlongpress = function(evt) {
          _dragDown = false;
          if(! _dragEnabled)return;
          _data.dragging = true;
          evt.preventDefault();
          offset = element.offset();
          element.centerX = (element.width()/2);
          element.centerY = (element.height()/2);
          element.addClass('dragging');
          _mx = (evt.pageX || evt.originalEvent.touches[0].pageX);
          _my = (evt.pageY || evt.originalEvent.touches[0].pageY);
          _tx=_mx-element.centerX-$window.scrollLeft()
          _ty=_my -element.centerY-$window.scrollTop();
          moveElement(_tx, _ty);
          $document.on(_moveEvents, onmove);
          $document.on(_releaseEvents, onrelease);
          $rootScope.$broadcast('draggable:start', {x:_mx, y:_my, tx:_tx, ty:_ty, element:element, data:_data});

        }
        var onmove = function(evt) {
          if(! _dragEnabled)return;

          // ensure mouse has moved a bit before we start dragging
          if (_dragDown) {
            if ((Math.abs(evt.pageX-_dragStartX) > 2) && (Math.abs(evt.pageY-_dragStartY) > 2)) {
              onlongpress(evt);
            }
            else {
              return;
            }
          }
          evt.preventDefault();

          _mx = (evt.pageX || evt.originalEvent.touches[0].pageX);
          _my = (evt.pageY || evt.originalEvent.touches[0].pageY);
          _tx=_mx-element.centerX-$window.scrollLeft()
          _ty=_my -element.centerY-$window.scrollTop();
          moveElement(_tx, _ty);

          $rootScope.$broadcast('draggable:move', {x:_mx, y:_my, tx:_tx, ty:_ty, element:element, data:_data});

        }
        var onrelease = function(evt) {
          _dragDown = true;
          if(! _dragEnabled)return;
          evt.preventDefault();
          $rootScope.$broadcast('draggable:end', {x:_mx, y:_my, tx:_tx, ty:_ty, element:element, data:_data, callback:onDragComplete});
          element.removeClass('dragging');
          reset();
          $document.off(_moveEvents, onmove);
          $document.off(_releaseEvents, onrelease);
//          $timeout(function(){
//            _data.dragging = false;
//          });
        }
        var onDragComplete = function(evt) {
          // clear dragging on timeout to stop ng-click event from triggering on drag/drop
          if(! onDragSuccessCallback)return;

          scope.$apply(function () {
            onDragSuccessCallback(scope, {$data: _data, $event: evt});
          });
//          setTimeout(function(){
//            _data.dragging = false;
//          },10);

//          $timeout(function(){
//            _data.dragging = false;
//          });
        }
        var reset = function() {
          element.css({left:'',top:'', position:'', 'z-index':''});
        }
        var moveElement = function(x,y) {
          element.css({left:x,top:y, position:'fixed', 'z-index':99999});
        }
        initialize();
      }
    }
  }])
  .directive('ngDrop', ['$parse', '$timeout', function ($parse, $timeout) {
    return {
      restrict: 'A',
      link: function (scope, element, attrs) {
        scope.value = attrs.ngDrop;

        var _dropEnabled=false;

        var onDropCallback = $parse(attrs.ngDropSuccess);// || function(){};
        var initialize = function () {
          toggleListeners(true);
        };


        var toggleListeners = function (enable) {
          // remove listeners

          if (!enable)return;
          // add listeners.
          attrs.$observe("ngDrop", onEnableChange);
          scope.$on('$destroy', onDestroy);
          //scope.$watch(attrs.uiDraggable, onDraggableChange);
          scope.$on('draggable:start', onDragStart);
          scope.$on('draggable:move', onDragMove);
          scope.$on('draggable:end', onDragEnd);
          scope.$watch(attrs.ngDropId, onDropIdChange);
        };
        var onDestroy = function (enable) {
          toggleListeners(false);
        };
        var onDropIdChange = function (newVal, oldVal) {
          if (newVal == undefined) {
            scope.dropid = [];
          }
          else {
            scope.dropid = newVal;
          }
        }
        var onEnableChange = function (newVal, oldVal) {
          _dropEnabled=scope.$eval(newVal);
        }
        var onDragStart = function(evt, obj) {
          if(! _dropEnabled)return;
          isTouching(obj.x,obj.y,obj.element);
        }
        var onDragMove = function(evt, obj) {
          if(! _dropEnabled)return;
          if((scope.dropid.length > 0) && (scope.dropid.indexOf(obj.data.dragid) < 0)) return;
          isTouching(obj.x,obj.y,obj.element);
        }
        var onDragEnd = function(evt, obj) {
          if(! _dropEnabled)return;
          if((scope.dropid.length > 0) && (scope.dropid.indexOf(obj.data.dragid) < 0)) return;
          if(isTouching(obj.x,obj.y,obj.element)){
            // call the ngDraggable element callback
            if(obj.callback){
              obj.callback(evt);
            }

            // call the ngDrop element callback
            //   scope.$apply(function () {
            //       onDropCallback(scope, {$data: obj.data, $event: evt});
            //   });
            $timeout(function(){
              onDropCallback(scope, {$data: obj.data, $event: evt});
            });


          }
          updateDragStyles(false, obj.element);
        }
        var isTouching = function(mouseX, mouseY, dragElement) {
          var touching= hitTest(mouseX, mouseY);
          updateDragStyles(touching, dragElement);
          return touching;
        }
        var updateDragStyles = function(touching, dragElement) {
          if(touching){
            element.addClass('drag-enter');
            dragElement.addClass('drag-over');
          }else{
            element.removeClass('drag-enter');
            dragElement.removeClass('drag-over');
          }
        }
        var hitTest = function(x, y) {
          var bounds = element.offset();
          bounds.right = bounds.left + element.outerWidth();
          bounds.bottom = bounds.top + element.outerHeight();
          return x >= bounds.left
            && x <= bounds.right
            && y <= bounds.bottom
            && y >= bounds.top;
        }

        initialize();
      }
    }
  }])
  .directive('ngDragClone', ['$parse', '$timeout', function ($parse, $timeout) {
    return {
      restrict: 'A',
      link: function (scope, element, attrs) {
        var img;
        scope.clonedData = {};
        var initialize = function () {

          img = $(element.find('img'));
          element.attr('draggable', 'false');
          img.attr('draggable', 'false');
          reset();
          toggleListeners(true);
        };


        var toggleListeners = function (enable) {
          // remove listeners

          if (!enable)return;
          // add listeners.
          scope.$on('draggable:start', onDragStart);
          scope.$on('draggable:move', onDragMove);
          scope.$on('draggable:end', onDragEnd);
          preventContextMenu();

        };
        var preventContextMenu = function() {
          //  element.off('mousedown touchstart touchmove touchend touchcancel', absorbEvent_);
          img.off('mousedown touchstart touchmove touchend touchcancel', absorbEvent_);
          //  element.on('mousedown touchstart touchmove touchend touchcancel', absorbEvent_);
          img.on('mousedown touchstart touchmove touchend touchcancel', absorbEvent_);
        }
        var onDragStart = function(evt, obj) {
          scope.$apply(function(){
            scope.clonedData = obj.data;
          });
          element.css('width', obj.element.height());
          element.css('height', obj.element.height());

          moveElement(obj.tx,obj.ty);
        }
        var onDragMove = function(evt, obj) {
          moveElement(obj.tx,obj.ty);
        }
        var onDragEnd = function(evt, obj) {
          //moveElement(obj.tx,obj.ty);
          reset();
        }

        var reset = function() {
          element.css({left:0,top:0, position:'fixed', 'z-index':-1, visibility:'hidden'});
        }
        var moveElement = function(x,y) {
          element.css({left:x,top:y, position:'fixed', 'z-index':99999, visibility:'visible'});
        }

        var absorbEvent_ = function (event) {
          var e = event.originalEvent;
          e.preventDefault && e.preventDefault();
          e.stopPropagation && e.stopPropagation();
          e.cancelBubble = true;
          e.returnValue = false;
          return false;
        }

        initialize();
      }
    }
  }])
  .directive('ngPreventDrag', ['$parse', '$timeout', function ($parse, $timeout) {
    return {
      restrict: 'A',
      link: function (scope, element, attrs) {
        var initialize = function () {

          element.attr('draggable', 'false');
          toggleListeners(true);
        };


        var toggleListeners = function (enable) {
          // remove listeners

          if (!enable)return;
          // add listeners.
          element.on('mousedown touchstart touchmove touchend touchcancel', absorbEvent_);
        };


        var absorbEvent_ = function (event) {
          var e = event.originalEvent;
          e.preventDefault && e.preventDefault();
          e.stopPropagation && e.stopPropagation();
          e.cancelBubble = true;
          e.returnValue = false;
          return false;
        }

        initialize();
      }
    }
  }]);

}(jQuery));
