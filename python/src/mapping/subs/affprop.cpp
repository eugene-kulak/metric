#include "modules/mapping/affprop.hpp"

#include <boost/python.hpp>
#include <vector>
#include <tuple>

namespace bp = boost::python;

template<typename recType, typename Metric, typename T>
bp::tuple affprop(const metric::Matrix<recType, Metric>& DM,
                  T preference = 0.5,
                  int maxiter = 200,
                  T tol = 1.0e-6,
                  T damp = 0.5) {
    auto result = metric::affprop(DM, preference, maxiter, tol, damp);
    return bp::make_tuple(std::get<0>(result), std::get<1>(result), std::get<2>(result));
}

template <typename recType, typename Metric, typename T>
void register_wrapper_affprop() {
    bp::def("affprop", &affprop<recType, Metric, T>,
        (
            bp::arg("dm"),
            bp::arg("preference") = 0.5,
            bp::arg("maxiter") = 200,
            bp::arg("tol") = 1.0e-6,
            bp::arg("damp") = 0.5
        )
    );
}

void export_metric_affprop() {
    register_wrapper_affprop<std::vector<double>, metric::Euclidian<double>, float>();
}

BOOST_PYTHON_MODULE(_affprop) {
    export_metric_affprop();
}