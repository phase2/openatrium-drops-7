<?php
/**
 * @file
 * Preprocess functions for comments.
 */

/**
 * Implements hook_theme().
 */
function oa_comment_theme($existing, $type, $theme, $path) {
  $views = array(
    'oa_comment_topics' => array(
      'comment_topics',
      'comment_user_topics',
      'comment_user_topics_replied',
    ),
    'oa_comment_media' => array(
      'commentnode_attachments',
    ),
  );
  $theme = array();
  foreach ($views as $view_name => $displays) {
    foreach ($displays as $display) {
      $key = 'views_view_fields__' . $view_name . '__' . $display;
      $filename = str_replace('_', '-', $key);
      $theme[$key] = array(
        'template'  => $filename,
        'base hook' => 'views_view_fields',
        'preprocess functions' => array(
          'template_preprocess',
          'template_preprocess_views_view_fields',
          'oa_core_preprocess_views_view_fields',
        ),
        'arguments' => array('view' => NULL, 'options' => NULL, 'row' => NULL),
        'path' => drupal_get_path('module', 'oa_comment') . '/templates',
      );
    }
  }
  // Provide theme implementation for comments.
  $theme['oa_comment__comment'] = array(
    'template' => 'oa-comment--comment',
    'render element' => 'elements',
    'path' => $path . '/templates',
  );
  $theme['oa_comment__comment_wrapper'] = array(
    'template' => 'oa-comment--comment-wrapper',
    'render element' => 'elements',
    'path' => $path . '/templates',
  );
  // Provide a theme implementation for the comment form.
  $theme['comment_form'] = array(
    'template' => 'oa-comment--comment-form',
    'render element' => 'form',
    'path' => $path . '/templates',
  );

  return $theme;
}

/**
 * Implements hook_preprocess_comment().
 */
function oa_comment_preprocess_comment(&$vars) {
  // Include ctools files.
  ctools_include('modal');
  ctools_include('ajax');

  $comment = $vars['comment'];
  $vars['show_links'] = TRUE;

  // Convert thread to a human comment number
  // First, remove trailing slash.
  $thread = substr($comment->thread, 0, -1);
  $parts = explode('.', $thread);
  foreach ($parts as $key => &$part) {
    $parts[$key] = vancode2int($part);
    // First id starts at 1, but rest start at zero.
    if ($key > 0) {
      $parts[$key]++;
    }
  }
  $vars['thread'] = implode('.', $parts);

  // Add our template for individual comments.
  $vars['theme_hook_suggestions'][] = 'oa_comment__comment';
  // If we are using ajax don't display the action links.
  if (strpos($_GET['q'], 'ajax') > 0) {
    $vars['show_links'] = FALSE;
  }
  // Render the paragraph field if this comment contains one.
  if (!empty($vars['elements']['field_oa_related'])) {
    $vars['paragraphs'] = render($vars['elements']['field_oa_related']);
  }
  // Get the user picture.
  $user_details = oa_users_build_user_details(user_load($comment->uid));
  $vars['user_picture'] = $user_details['picture'];
  $vars['body'] = (!empty($comment->comment_body[LANGUAGE_NONE][0]['safe_value'])) ? $comment->comment_body[LANGUAGE_NONE][0]['safe_value'] : NULL;
  $vars['comment_link'] = l(t('#!comment_id', array('!comment_id' => $vars['thread'])), 'node/' . $vars['node']->nid, array(
    'attributes' => array(
      'class' => array(
        'oa-pullout-left',
      ),
      'title' => t('Copy this link to share.')), 'fragment' => 'comment-' . $comment->cid));

  // Remove Reply link if comments are not threaded
  $threaded = variable_get('comment_default_mode_' . $vars['node']->type, COMMENT_MODE_THREADED);
  if (!$threaded) {
    unset($vars['content']['links']['comment']['#links']['comment-reply']);
  }

  // Action links for each comment.
  // @todo Figure out how do add delete confirm_form in modal.
  $links = array();
  foreach ($vars['content']['links']['comment']['#links'] as $key => $link) {
    if (in_array($key, array('comment-edit', 'comment-reply'))) {
      // Convert these comment links to ajax callbacks
      $links[$key] = ctools_modal_text_button($link['title'], 'oa/nojs/' . $link['href'], $link['title']);
    }
    elseif (!isset($link['href'])) {
      $links[$key] = !empty($link['html']) ? $link['title'] : check_plain($link['title']);
    }
    else {
      $links[$key] = l($link['title'], $link['href'], $link);
    }
  }
  $vars['comment_links'] = $links;
}

/**
 * Implements hook_preprocess_comment_wrapper().
 */
function oa_comment_preprocess_comment_wrapper(&$vars) {
  // Add our template for comments using the combined comment widget.
  $vars['theme_hook_suggestions'][] = 'oa_comment__comment_wrapper';
}

/**
 * Implements hook_preprocess_comment_form().
 */
function oa_comment_preprocess_comment_form(&$vars) {
  $form = $vars['form'];
  // Make sure this is a modal.
  if (strpos($form['#action'], 'ajax') !== FALSE) {
    // Only show the parent comment in the modal if there is one.
    if (!empty($form['#entity']->pid)) {
      $cid = $form['#entity']->pid;
      $comment = comment_load($cid);
      $comment = comment_view($comment, $vars['form']['#node']);

      if (isset($comment)) {
        // Remove comment links in modal.
        $vars['comment_parent'] = drupal_render($comment);
      }
    }
  }
  $vars['paragraph_buttons'] = drupal_render($form['field_oa_related']);
  $vars['action_links'] = drupal_render($form['actions']);
  // Render the rest of the comment form.
  $vars['comment_form'] = drupal_render_children($form);
}
