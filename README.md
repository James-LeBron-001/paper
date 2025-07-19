# MetaPopulation SEIR Epidemic Simulation Model

This project contains the model code used in my research paper. In short, it is a modular C++ simulation based on the extend SEIR epidemiological model, combined with the metapopulation modeling approach. All experiments in the paper are conducted using this simulation framework. To facilitate reproducibility, learning, and further research, I have carefully organized, documented, and modularized the code. I hope this project will serve as a clear and practical reference for others interested in epidemic modeling and simulation.


## Project Structure

```
model/
  ├── include/                # Header files (.h)
  │     ├── SEIRModel.h
  │     ├── Population.h
  │     ├── Migration.h
  │     ├── Transition.h
  │     ├── IOUtils.h
  │     ├── Config.h
  │     └── RandomUtils.h
  ├── src/                    # Source files (.cpp)
  │     ├── main.cpp
  │     ├── SEIRModel.cpp
  │     ├── Population.cpp
  │     ├── Migration.cpp
  │     ├── Transition.cpp
  │     ├── IOUtils.cpp
  │     ├── Config.cpp
  │     └── RandomUtils.cpp
  ├── CMakeLists.txt          # Build script
  └── README.md               # Project documentation
```

> Note: If your files are not yet physically separated into include/ and src/ folders, you can easily move them for better organization. Update your CMakeLists.txt accordingly.

## Build Instructions
This project uses CMake for cross-platform builds.

```
mkdir build
cd build
cmake ..
make
```
The executable `seir_simulation` will be generated in the `build` directory.

---
For questions or contributions, please open an issue or pull request on GitHub. 