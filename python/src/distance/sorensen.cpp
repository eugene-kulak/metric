#include "modules/distance/k-related/L1.hpp"

#include <boost/python.hpp>
#include <vector>

namespace bp = boost::python;


template<typename Value>
void register_wrapper() {
    {
        using Specialization = double (*)(const blaze::CompressedVector<Value>&, const blaze::CompressedVector<Value>&);
        bp::def<Specialization>("sorensen", &metric::sorensen<Value>);
    }

    {
        using Specialization = double (*)(const std::vector<Value>&, const std::vector<Value>&);
        bp::def<Specialization>("sorensen", &metric::sorensen<std::vector<Value>>);
    }
}

void export_metric_sorensen() {
    register_wrapper<double>();
}
