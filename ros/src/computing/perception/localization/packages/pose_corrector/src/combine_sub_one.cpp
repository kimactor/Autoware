/*
 *  Copyright (c) 2017, Tier IV, Inc.
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions are met:
 *
 *  * Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 *  * Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 *  * Neither the name of Autoware nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 *  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 *  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 *  DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 *  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 *  OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include <vector>
#include <deque>

#include <ros/ros.h>
#include <geometry_msgs/TwistStamped.h>

#include <boost/shared_ptr.hpp>

#include "pose_corrector/combine_sub_one.h"
#include "pose_corrector/combine_sub_base.h"
#include "pose_corrector/sub_base.h"

CombineSubOne::CombineSubOne(const boost::shared_ptr<const SubBase>& sub) :
    sub_ptr_(sub)
{

}

CombineSubOne::~CombineSubOne()
{

}

std::vector<geometry_msgs::TwistStamped> CombineSubOne::getCombinedArray() const
{
  std::vector<geometry_msgs::TwistStamped> combined_array;
  
  auto queue = sub_ptr_->getQueue();
  
  for(const auto& data :queue)
  {
    auto d = getCombinedData(data);
    combined_array.push_back(d);
  }

  return combined_array;
}

inline geometry_msgs::TwistStamped CombineSubOne::getCombinedData(const geometry_msgs::TwistStamped& data) const
{
  return data;
}

