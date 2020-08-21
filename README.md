# MplColormapsCpp

MplColormapsCpp offers easy access to use the infamous [Matplotlib Colormaps](https://bids.github.io/colormap/).

The functionality is implemented in C++17 as header only lib.

Available colormaps are:
* **Viridis** ![](doc/colormap_viridis.svg)
* **Inferno** ![](doc/colormap_inferno.svg)
* **Magma** ![](doc/colormap_magma.svg)
* **Plasma** ![](doc/colormap_plasma.svg)

The colormaps may be used as follows:

```{cpp}
#include <mpl_colormaps/mpl_colormaps.hpp>

void Example()
{
  std::array<float, 3> rgb_viridis = mpl_colormaps::MapViridis(0.5F);
  std::array<float, 3> rgb_inferno = mpl_colormaps::MapInferno(1.F);
  /*...*/
}
```

## License

The same as the colormaps themselves, [CC0 Public Domain](LICENSE).