/*
  MplColormapsCpp by Lukas Riebel, 2020
  Released under the CC0 license / public domain dedication
  (https://creativecommons.org/publicdomain/zero/1.0/)

  Matplotlib Colormaps developed by Nathaniel J. Smith, Stefan van der Walt,
  and (in the case of viridis) Eric Firing.
  See https://github.com/BIDS/colormap/blob/master/colormaps.py,
  https://github.com/BIDS/colormap/blob/master/colormaps.py
*/

#ifndef MPL_COLORMAPS_HPP
#define MPL_COLORMAPS_HPP

#include <array>
#include <algorithm> 
#include <cmath>

#include "mpl_colormaps_impl.hpp"

namespace mpl_colormaps
{
namespace internal
{
  template<typename T>
  constexpr T Lerp(T t, T from, T to)
  {
    return (T(1) - t) * from + t * to;
  }

  template<size_t Dim>
  constexpr std::array<float, 3> Map(float t,
                                     const std::array<std::array<float, 3>, Dim>& color_map)
  {
    const auto t_clamped = std::clamp(t, 0.F, 1.F);

    const size_t bin = static_cast<size_t>(t_clamped * (Dim - 1));

    const auto& t_from = color_map[bin > 0 ? bin - 1 : bin];
    const auto& t_to = color_map[bin + 1 < Dim ? bin + 1 : bin];

    constexpr float bin_width = 1.f / Dim;

    const float r_t = std::fmodf(t_clamped, bin_width) / bin_width;

    return {Lerp(r_t, t_from[0], t_to[0]), Lerp(r_t, t_from[1], t_to[1]),
            Lerp(r_t, t_from[2], t_to[2])};
  }

}  // namespace internal

/**
\brief Maps a scalar in [0,1] to a color from the Viridis color map. Values for @a t outside
     of [0,1] will clamped.
*/
constexpr std::array<float, 3> MapViridis(float t)
{
  return internal::Map(t, maps::Viridis);
}

/**
  \brief Maps a scalar in [0,1] to a color from the Plasma color map. Values for @a t outside
         of [0,1] will clamped.
*/
constexpr std::array<float, 3> MapPlasma(float t)
{
  return internal::Map(t, maps::Plasma);
}

/**
  \brief Maps a scalar in [0,1] to a color from the Magma color map. Values for @a t outside
         of [0,1] will clamped.
*/
constexpr std::array<float, 3> MapMagma(float t)
{
  return internal::Map(t, maps::Magma);
}

/**
  \brief Maps a scalar in [0,1] to a color from the Inferno color map. Values for @a t outside
         of [0,1] will clamped.
*/
constexpr std::array<float, 3> MapInferno(float t)
{
  return internal::Map(t, maps::Inferno);
}
}  // namespace mpl_colormaps

#endif  // MPL_COLORMAPS_HPP