<?php

/**
 * Implements hook_block_info().
 */
function social_icons_block_info() {
  $blocks['social_icons'] = array(
    'info' => t('Block Social Icons'),
    'status' => FALSE,

  );
  return $blocks;
}

/**
 * Implements hook_block_view().
 */
function social_icons_block_view($delta = '') {
  switch ($delta) {
    case 'social_icons':
      $block['subject'] = t('Social Icons');
      $block['content'] = social_icons_block_contents($delta);
      return $block;
      break;
  }
}

/**
 * Implements hook_block_configure().
 */
function social_icons_block_configure($delta = '') {
  $form= array();
  switch ($delta) {
    case 'social_icons':

      $form['social_icons_width'] = array(
        '#title' =>t('Width for icon.'),
        '#type' => 'textfield',
        '#size' => 3,
        '#descritpion' => t('Default value 50px'),
        '#default' => variable_get('social_icons_width', 50),
        '#suffix' => 'px',
      );
      $form['social_icons_height'] = array(
        '#title' => t('Height for icon.'),
        '#type' => 'textfield',
        '#size' => 3,
        '#descritpion' => t('Default value 50px'),
        '#default' => variable_get('social_icons_height', 50),
        '#suffix' => 'px',
      );
      $form['social_icons_position'] = array(
        '#title' => t('Position'),
        '#type' => 'select',
        '#options' => array(
          'gorisontal' => t('Gorisontal'),
          'vertical' => t('Vertical'),
        ),
        '#size' => 3,
        '#descritpion' => t('Default value 50px'),
        '#default' => variable_get('social_icons_position', 'vertical'),
        '#suffix' => 'px',
      );
      break;
  }
  return $form;

}

/**
 * Implements hook_block_save().
 */
function social_icons_block_save($delta = '', $edit = array()) {
  switch ($delta) {
    case 'social_icons':
      variable_set('social_icons_width', (int)$edit['social_icons_width'] );
      variable_set('social_icons_height', (int)$edit['social_icons_height'] );
      variable_set('social_icons_position', $edit['social_icons_position'] );
      break;
  }
  return;
}

/**
 * @param $delta
 * @return string
 */
function social_icons_block_contents($delta) {
  switch ($delta) {
    case 'social_icons':
      $query = db_select('social_icons', 'si')
        ->fields('si', array('id'))
        ->orderBy('si.id')
        ->execute();
      $output = '';

      foreach ($query as $icon) {
        $entity = social_icons_load($icon->id);
        var_dump($icon);
        $output .= '<a href="' . $entity->link .'" >';
        $output .= '<img src="'. file_create_url(file_load($entity->icon)->uri). '"';
        $output .=  'width="' . variable_get('social_icons_width', 50) . 'px" height="' . variable_get('social_icons_height', 50) . 'px"/></a>';

      }
      return $output;
        //array('#markup' => theme('item_list', array('items' => $icons)));
    break;

  }

}