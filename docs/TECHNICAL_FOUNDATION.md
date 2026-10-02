# SPIDEY — Technical Foundation

## 1. Project Identity

Spidey is a custom AI system designed and developed from the ground up.

The objective is to create our own internal architecture for representation,
attention, reasoning, memory, learning, and behavior.

Spidey is not a wrapper around an existing AI model.

---

## 2. Core Principles

### 2.1 Build From Scratch

Spidey's core intelligence must be designed and implemented by us.

We will not use a pretrained model as Spidey's underlying brain.

### 2.2 Architecture Before Implementation

We will define what a system is supposed to do before implementing it.

No major subsystem should be added simply because it is common in modern AI.

### 2.3 Representation Is an Open Research Problem

Spidey will not automatically adopt conventional tokenization.

The internal representation of language will be researched and experimented
with before being finalized.

### 2.4 Structural Understanding

Spidey should work with relationships between information, including:

- goals
- constraints
- context
- dependencies
- focus
- uncertainty
- workflow state
- memory

### 2.5 Attention

Attention should determine what information is important to the current
problem and dynamically adjust focus as the internal state changes.

### 2.6 Reasoning

Reasoning should operate over Spidey's internal representations and
relationships rather than being reduced to simple text prediction.

### 2.7 Learning

Spidey should be designed to improve from experience and interaction without
requiring an external pretrained brain.

---

## 3. Development Stack

### Core

- Language: C++20
- Compiler: GCC / MinGW-w64 through MSYS2 UCRT64
- Build system: CMake
- Version control: Git
- Debugger: GDB
- Mathematics: Eigen
- Testing: GoogleTest

### GPU

CUDA may be introduced later for computationally expensive workloads.

GPU implementation will not be allowed to dictate the architecture.

---

## 4. Cost Constraint

The project must remain completely free to develop.

No paid APIs, paid cloud services, paid development tools, or paid AI models
are required for the core project.

Local hardware is the primary development environment.

---

## 5. Current Hardware Target

Initial development target:

- NVIDIA RTX 3050 Laptop GPU — 6 GB VRAM
- 16 GB system RAM

The architecture should remain efficient enough to experiment locally.

---

## 6. Initial System Areas

The planned system areas are:

1. Input
2. Representation / Encoding
3. Internal Structure
4. Attention
5. Reasoning
6. Workflow
7. Memory
8. Learning
9. Personality / Behavior
10. Output

These areas are provisional and may change as research reveals better
architectural approaches.

---

## 7. Deferred Decisions

The following are intentionally not finalized yet:

- exact encoding system
- tokenization strategy
- neural architecture
- learning architecture
- memory implementation
- GPU architecture
- long-term storage format

These decisions require research and experimentation.

---

## 8. Interface

The graphical interface and visual Spider-Man theme are intentionally
deferred.

Current development priority is the system behind the interface.

---

## 9. Development Philosophy

Spidey will be developed incrementally.

Each subsystem should be:

- understandable
- testable
- measurable
- replaceable when research shows a better approach

We will avoid unnecessary dependencies and unnecessary abstraction.

---

## 10. Project Rule

Do not confuse using a tool with outsourcing intelligence.

Libraries may provide mathematics, compilation, testing, storage, or other
infrastructure.

The architecture and behavior of Spidey's intelligence must remain our own
design.