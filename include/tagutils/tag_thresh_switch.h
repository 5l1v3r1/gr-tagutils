/* -*- c++ -*- */
/* 
 * Copyright 2014 Adam Gannon.
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


#ifndef INCLUDED_TAGUTILS_TAG_THRESH_SWITCH_H
#define INCLUDED_TAGUTILS_TAG_THRESH_SWITCH_H

#include <tagutils/api.h>
#include <gnuradio/sync_block.h>

namespace gr {
  namespace tagutils {

    /*!
     * \brief Switch input based on value of stream tag
     * \ingroup tagutils
     *
     */
    class TAGUTILS_API tag_thresh_switch : virtual public gr::sync_block
    {
     public:
      typedef boost::shared_ptr<tag_thresh_switch> sptr;

      enum value_thresh_comp_type
      {
            ABOVE,
            BELOW,   
            EQUAL
      };

      /*!
       * Searches for a stream tag matching the key parameter and gets its value.
       * If the value is above the threshold, copies the input to the 'above' port
       * If the value is above the threshold, copies the input to the 'below' port
       * User can select to which port the input is copied to when value equals threshold
       */
      static sptr make(size_t itemsize, const std::string &key_filter, double threshold, bool debug, bool above_if_equal);

      virtual void set_threshold(double threshold) = 0;
    };

  } // namespace tagutils
} // namespace gr

#endif /* INCLUDED_TAGUTILS_TAG_THRESH_SWITCH_H */

