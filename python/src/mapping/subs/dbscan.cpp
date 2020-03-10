#include "modules/mapping/dbscan.hpp"

#include <boost/python.hpp>
#include <tuple>
#include <vector>

namespace bp = boost::python;

template<typename recType, typename Metric, typename T>
bp::tuple dbscan(const metric::Matrix<recType, Metric>& dm, T eps, std::size_t minpts) {
    auto result = metric::dbscan(dm, eps, minpts);
    return bp::make_tuple(std::get<0>(result), std::get<1>(result), std::get<2>(result));
}

template<typename recType, typename Metric, typename T>
void register_wrapper_dbscan() {
    bp::def("dbscan", &dbscan<recType, Metric, T>);
}

void export_metric_dbscan() {
    register_wrapper_dbscan<std::vector<double>, metric::Euclidian<double>, double>();
}

BOOST_PYTHON_MODULE(_dbscan) {
    export_metric_dbscan();
}