/* -*- c++ -*- */

#define TAGUTILS_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "tagutils_swig_doc.i"

%{
#include "tagutils/tag_thresh_switch.h"
#include "tagutils/tag_to_byte_c.h"
#include "tagutils/tag_to_byte_f.h"
#include "tagutils/tag_to_byte_b.h"
#include "tagutils/add_tag_at_offset.h"
#include "tagutils/tag_extract_cc.h"
%}


%include "tagutils/tag_thresh_switch.h"
GR_SWIG_BLOCK_MAGIC2(tagutils, tag_thresh_switch);


%include "tagutils/tag_to_byte_c.h"
GR_SWIG_BLOCK_MAGIC2(tagutils, tag_to_byte_c);
%include "tagutils/tag_to_byte_f.h"
GR_SWIG_BLOCK_MAGIC2(tagutils, tag_to_byte_f);
%include "tagutils/tag_to_byte_b.h"
GR_SWIG_BLOCK_MAGIC2(tagutils, tag_to_byte_b);
%include "tagutils/add_tag_at_offset.h"
GR_SWIG_BLOCK_MAGIC2(tagutils, add_tag_at_offset);
%include "tagutils/tag_extract_cc.h"
GR_SWIG_BLOCK_MAGIC2(tagutils, tag_extract_cc);
