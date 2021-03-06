<?php

class article extends atkNode
{
  public function __construct()
  {
    parent::__construct("article", NF_EXPORT);

    $this->add(new atkAttribute("id", AF_AUTOKEY));
    $this->add(new atkAttribute("title", AF_OBLIGATORY | AF_SEARCHABLE));
    $this->add(new atkAttribute("author", AF_OBLIGATORY | AF_SEARCHABLE));

    $this->setTable("article");

    // add relationship to issue node
    $this->add(new atkManyToOneRelation("issue_id",
                                        "magman.issue", AF_SEARCHABLE));

    // add descriptor template
    $this->setDescriptorTemplate("[title] by [author]");

    // add relationship to category node
    $this->add(new atkManyToOneRelation("category_id",
                                        "magman.category", AF_SEARCHABLE));
  }
}
