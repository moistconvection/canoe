// athena
#include <athena/mesh/mesh.hpp>

// canoe
#include <configure.hpp>
#include <variable.hpp>

// application
#include <application/exceptions.hpp>

// opacity
#include "absorption_functions.hpp"
#include "mwr_absorbers.hpp"

namespace GiantPlanets {

MwrAbsorberCIA::MwrAbsorberCIA(MeshBlock* pmb, std::vector<std::string> species,
                               ParameterMap params)
    : Absorber(pmb, "radio-CIA", species, params) {
  if (!params_.count("xHe")) {
    throw NotFoundError("MwrAbsorberCIA", "parameter 'xHe'");
  }

  if (!params_.count("xCH4")) {
    throw NotFoundError("MwrAbsorberCIA", "parameter 'xCH4'");
  }

  if (!params_.count("mix")) {
    throw NotFoundError("MwrAbsorberCIA", "parameter 'mix'");
  }
}

Real MwrAbsorberCIA::GetAttenuation(Real wave1, Real wave2,
                                    Variable const& var) const {
  Real P = var.w[IPR] / 1.E5;  // pa -> bar
  Real T = var.w[IDN];
  Real xdry = 1.;
  for (int i = 1; i <= NVAPOR; ++i) xdry -= var.w[i];
  Real XHe = params_.at("xHe") * xdry;
  Real XCH4 = params_.at("xCH4") * xdry;
  Real XH2 = (1. - params_.at("xHe") - params_.at("xCH4")) * xdry;
  Real mix = params_.at("mix");
  Real wave = (wave1 + wave2) / 2.;

  // 1/cm -> 1/m
  return 100. * absorption_coefficient_CIA(wave, P, T, XH2, XHe, XCH4, mix);
}

}  // namespace GiantPlanets
