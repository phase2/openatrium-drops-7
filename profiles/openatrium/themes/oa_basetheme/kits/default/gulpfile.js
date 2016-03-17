'use strict';
var gulp = require('gulp-help')(require('gulp'));
var yaml = require('js-yaml');
var fs = require('fs');
var config = yaml.safeLoad(fs.readFileSync('./config.yml', 'utf8'));
var tasks = {
  'compile': [],
  'watch': [],
  'validate': [],
  'clean': [],
  'default': []
};

require('p2-theme-core/index.js')(gulp, config, tasks);

if (config.fonts.enabled) {
  gulp.task('fonts', function () {
    return gulp.src(config.fonts.src)
      .pipe(gulp.dest(config.fonts.dest));
  });
}

gulp.task('compile', tasks.compile);
gulp.task('clean', tasks.clean);
gulp.task('validate', tasks.validate);
gulp.task('watch', tasks.watch);
tasks.default.push('compile');
tasks.default.push('watch');
tasks.compile.push('fonts');
gulp.task('default', tasks.default);
