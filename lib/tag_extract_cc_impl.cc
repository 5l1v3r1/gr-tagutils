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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "tag_extract_cc_impl.h"

namespace gr {
  namespace tagutils {

    tag_extract_cc::sptr
    tag_extract_cc::make(const std::string &tag_key, bool debug)
    {
      return gnuradio::get_initial_sptr
        (new tag_extract_cc_impl(tag_key, debug));
    }

  
    tag_extract_cc_impl::tag_extract_cc_impl(const std::string &tag_key, bool debug)
      : gr::sync_block("tag_extract_cc",
              gr::io_signature::make(1,1, sizeof(gr_complex)),
              gr::io_signature::make(1,1, sizeof(gr_complex))),
              d_debug(debug), d_offset(std::numeric_limits<unsigned long>::max())
    {
      set_tag_key(tag_key); 
    }


    tag_extract_cc_impl::~tag_extract_cc_impl()
    {
    }
    
    void
    tag_extract_cc_impl::set_tag_key(const std::string &tag_key)
    {
      if(tag_key == "")
        d_key = pmt::intern("packet_len");
      else
        d_key = pmt::intern(tag_key);
    }
    
    void 
    tag_extract_cc_impl::search_for_tag(int nread, int noutput)
    {
      std::vector<gr::tag_t> d_tags;
      get_tags_in_range(d_tags, 0, nread, nread + noutput, d_key);
      
      for(d_tags_itr = d_tags.begin(); d_tags_itr != d_tags.end(); d_tags_itr++) {
        d_offset = d_tags_itr->offset;
        d_value = pmt::to_complex(d_tags_itr->value);
        
      }
    }

    int
    tag_extract_cc_impl::work(int noutput_items,
			  gr_vector_const_void_star &input_items,
			  gr_vector_void_star &output_items)
    {
        const gr_complex *in = (const gr_complex *) input_items[0];
        gr_complex *out = (gr_complex *) output_items[0];
        unsigned long nread = nitems_read(0);

        
        search_for_tag(nread,noutput_items);

        for (int i=0;i<noutput_items;i++) {
          
          if ((nread+i) == d_offset){
            out[i] = d_value;
          }
          else {
            out[i] = 0;
          }
        }
        
        
        return noutput_items;
    }

  } /* namespace tagutils */
} /* namespace gr */

