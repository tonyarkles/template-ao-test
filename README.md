# What is this?

A super simple wrapper around a class that turns it into a thread. At
destruction, the ActiveObject signals the thread that it's time to
shut down and waits for the thread to shutdown gracefully before
invoking the wrapped class's destructor.

# How to build

```
mkdir build
cd build
cmake ..
make
```
