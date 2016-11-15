#pragma once

#include "TimingAnalyzer.hpp"
#include "TimingTags.hpp"
#include "timing_graph_fwd.hpp"

namespace tatum {

/**
 * HoldTimingAnalyzer represents an abstract interface for all timing analyzers
 * performing hold (i.e. short-path) analysis.
 *
 * Note the use of virtual inheritance to avoid duplicating the base class
 */
class HoldTimingAnalyzer : public virtual TimingAnalyzer {
    public:
        TimingTags::tag_range get_hold_data_tags(NodeId node_id) const { return get_hold_data_tags_impl(node_id); }
        TimingTags::tag_range get_hold_launch_clock_tags(NodeId node_id) const { return get_hold_launch_clock_tags_impl(node_id); }
        TimingTags::tag_range get_hold_capture_clock_tags(NodeId node_id) const { return get_hold_capture_clock_tags_impl(node_id); }

    protected:
        virtual TimingTags::tag_range get_hold_data_tags_impl(NodeId node_id) const = 0;
        virtual TimingTags::tag_range get_hold_launch_clock_tags_impl(NodeId node_id) const = 0;
        virtual TimingTags::tag_range get_hold_capture_clock_tags_impl(NodeId node_id) const = 0;
};

} //namepsace
