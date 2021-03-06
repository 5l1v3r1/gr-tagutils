/* -*- c++ -*- */
/* 
 * Copyright 2014 <+YOU OR YOUR COMPANY+>.
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */


#ifndef INCLUDED_TAGUTILS_TAG_EXTRACT_CC_H
#define INCLUDED_TAGUTILS_TAG_EXTRACT_CC_H

#include <tagutils/api.h>
#include <gnuradio/sync_block.h>

namespace gr {
  namespace tagutils {

    /*!
     * \brief <+description of block+>
     * \ingroup tagutils
     *
     */
    class TAGUTILS_API tag_extract_cc : virtual public gr::sync_block
    {
     public:
      typedef boost::shared_ptr<tag_extract_cc> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of tagutils::tag_extract_cc.
       *
       * To avoid accidental use of raw pointers, tagutils::tag_extract_cc's
       * constructor is in a private implementation
       * class. tagutils::tag_extract_cc::make is the public interface for
       * creating new instances.
       */
      static sptr make(const std::string &tag_key, bool debug);
    };

  } // namespace tagutils
} // namespace gr

#endif /* INCLUDED_TAGUTILS_TAG_EXTRACT_CC_H */

