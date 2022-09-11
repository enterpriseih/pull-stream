# pull-stream
A simple pull-stream in C++.
## Intro
Once the duplex stream links, the sink will send a **Request** to peer's sources.

Then, when source has message, it **Consume**s the **Request**.

If the sink received a message, it will automatically send a new **Request**.

## Table of Contents
- include: Head files
- src: Example(s)
- test: A series of gtests

## Example
```C++
#include "../include/duplex.h"

int main() {
    std::string message_A = "A@1";
    std::string message_B = "B@1";
    Duplex<std::string> a("A", message_A);
    Duplex<std::string> b("B", message_B);
    link(a, b);
    b.consume("B@1");
    b.consume("B@2");
    b.consume("B@3");
}
```

## Chain-like Example
```C++
#include "../include/duplex.h"

int main() {
    Sink<std::string> c("C");
    Source<std::string> d("D", "D@1");
    c.pull(d);
    d.consume();
    return 0;
    }
```