<?php
class views_study_handler_filter_numeric_greater_500 extends views_handler_filter_numeric{
     public function operators(){

         $operators = parent::operators();

         $operators['greater_fivehandred'] = array(

             'title' => ('Is Greater Than 500'),

             'method' => 'op_gt_fivehandred',

             'short' => t("> 500"),
            
             'values' => 0 
         );
         return $operators;
     }

     public function op_gt_fivehandred($field){

         $this->query->add_where_expression($this->options['group'],"$field > 500");
     }
 }