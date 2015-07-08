<?php

// Plugin definition
$plugin = array(
  'title' => t('Four columns'),
  'category' => t('Columns: 4'),
  'icon' => 'fourcol.png',
  'theme' => 'panels_fourcol',
  'css' => 'fourcol.css',
  'regions' => array(
    'left' => t('Left side'),
    'left1' => t('Left side1'),
    'right' => t('Right side'),
    'right1' => t('Right side1'),
  ),
);
