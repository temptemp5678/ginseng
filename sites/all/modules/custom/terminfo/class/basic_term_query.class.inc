<?php
/**
 * @file
 */

/**
 * class
 * $TermQuery = new TermQuery();
 * $TermQuery->allProgramTid();
 */
class TermQuery {
  /**
   * @parameter ,
   *
   * @return array,
   * all Product NID
   */
  public function allProgramTid() {
    $query = new EntityFieldQuery;
    $query->entityCondition('entity_type', 'taxonomy_term')
      ->entityCondition('bundle', 'program');

    $result = $query->execute();

    $nid_array = NULL;
    if (isset($result['taxonomy_term'])) {
      if (count($result['taxonomy_term']) > 0 ) {
        $nid_array = array_keys($result['taxonomy_term']);
      }
    }

    return $nid_array;
  }

  /** - - - - - - other - - - - - - - - - - - - - - - - - - - - - - - - - -  */

}
