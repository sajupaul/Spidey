@'
<div align="center">

# 🕷️ SPIDEY

### `A custom AI architecture built from the ground up.`

**Not a wrapper.**  
**Not a downloaded brain.**  
**Not a pretrained model wearing a new mask.**

> **We are building Spidey from the inside out.**

<br>

![C++](https://img.shields.io/badge/Core-C%2B%2B20-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
![CMake](https://img.shields.io/badge/Build-CMake-064F8C?style=for-the-badge&logo=cmake&logoColor=white)
![Git](https://img.shields.io/badge/Version_Control-Git-F05032?style=for-the-badge&logo=git&logoColor=white)
![Status](https://img.shields.io/badge/Status-Research%20%26%20Development-B71C1C?style=for-the-badge)

<br>

`🕸️ ENCODE • FOCUS • REASON • REMEMBER • LEARN 🕸️`

</div>

---

<div align="center">

## 🕸️ THE SPIDER WEB

```text
                         ┌───────────────┐
                         │     INPUT     │
                         └───────┬───────┘
                                 │
                                 ▼
                         ┌───────────────┐
                         │    ENCODE     │
                         │      ???      │
                         └───────┬───────┘
                                 │
                ┌────────────────┴────────────────┐
                │                                 │
                ▼                                 ▼
        ┌───────────────┐                 ┌───────────────┐
        │   STRUCTURE   │◄───────────────►│    MEMORY     │
        └───────┬───────┘                 └───────┬───────┘
                │                                 │
                └──────────────┬──────────────────┘
                               ▼
                        ┌───────────────┐
                        │   ATTENTION   │
                        └───────┬───────┘
                                │
                                ▼
                        ┌───────────────┐
                        │   REASONING   │
                        └───────┬───────┘
                                │
                                ▼
                        ┌───────────────┐
                        │    WORKFLOW   │
                        └───────┬───────┘
                                │
                                ▼
                        ┌───────────────┐
                        │    LEARNING   │
                        └───────┬───────┘
                                │
                                ▼
                         ┌───────────────┐
                         │    OUTPUT     │
                         └───────────────┘


🕷️ WHAT IS SPIDEY?
Spidey is a long-term research and engineering project focused on
building a custom AI system from the ground up.
The goal isn't simply to create another chatbot.
The goal is to explore how an intelligent system can:
- understand information
- build internal representations
- maintain context
- determine what matters
- reason over relationships
- maintain memory
- revise beliefs
- learn from experience
- adapt over time
Spidey's architecture is being designed before the implementation is
locked in.
That means we're willing to question assumptions that are common in modern AI.
🕸️ THE RULE
┌─────────────────────────────────────────────────────┐
│                                                     │
│      DON'T BUILD IT BECAUSE EVERYONE BUILDS IT.    │
│                                                     │
│      UNDERSTAND IT.                                │
│      TEST IT.                                      │
│      BREAK IT.                                     │
│      REBUILD IT.                                   │
│                                                     │
└─────────────────────────────────────────────────────┘

Spidey's architecture should emerge from experiments rather than imitation.
🔬 THE BIG EXPERIMENT
One of the biggest unanswered questions is:
How should Spidey represent information internally?
We are deliberately not assuming conventional tokenization is the answer.
The research currently investigates:
                    LANGUAGE
                        │
                        ▼
                 ┌─────────────┐
                 │      ?      │
                 │ REPRESENT   │
                 └──────┬──────┘
                        │
            ┌───────────┼───────────┐
            ▼           ▼           ▼
        Structure    Relations    State
            │           │           │
            └───────────┼───────────┘
                        ▼
                  SITUATION MODEL

The representation system remains an open research problem.
🧠 WHAT SPIDEY MAY NEED TO REPRESENT
Our current research identifies candidate information units such as:
ENTITY
STATE
ACTION
GOAL
CONSTRAINT
RELATIONSHIP
CAUSE
RESULT
CONDITION
EVIDENCE
HYPOTHESIS
UNCERTAINTY
CONTEXT
REFERENCE
TIME
BELIEF
OBSERVATION
CONTRADICTION
IDENTITY
COMPOSITION

These are research hypotheses, not a final ontology.
👁️ ATTENTION
Spidey's attention system is intended to answer:
What matters right now?

Not simply:
“Which word is next to which word?”

Possible attention signals include:
┌──────────────────────────────┐
│ CURRENT GOAL                 │
│ CURRENT TASK                 │
│ RELEVANT MEMORY              │
│ IMPORTANT RELATIONSHIPS      │
│ CONSTRAINTS                  │
│ UNCERTAINTY                  │
│ NEW EVIDENCE                 │
│ RECENT CHANGES               │
│ WORKFLOW STATE               │
└──────────────────────────────┘
                │
                ▼
             FOCUS
The actual mechanism is still under research.
🧩 REASONING
Spidey should eventually be able to work with structures such as:
Observation
      ↓
Interpretation
      ↓
Hypothesis
      ↓
Evidence
      ↓
Belief
      ↓
Revision
      ↓
New reasoning

🧠 MEMORY
Memory is not intended to be:
conversation_history.txt
and nothing more.
We're exploring structured memory containing concepts such as:
FACT
DECISION
PREFERENCE
EXPERIENCE
LESSON
BELIEF
GOAL
PROJECT STATE

Potential memory structure:
MEMORY
│
├── Content
├── Type
├── Source
├── Time
├── Confidence
├── Relationships
├── Importance
├── Usage History
└── Revision History
This remains experimental.

GOAL
    ↓
What are we trying to achieve?

CONSTRAINT
    ↓
What are we not allowed to change?

DEPENDENCY
    ↓
What depends on what?

OBSERVATION
    ↓
What do we know happened?

HYPOTHESIS
    ↓
What might explain it?
This distinction becomes important when Spidey starts planning and reasoning.

🕸️ WORKING SITUATION
One architectural idea currently emerging is a dynamic working situation.
WORKING SITUATION
│
├── Entities
├── States
├── Events
├── Relationships
├── Goals
├── Constraints
├── Observations
├── Beliefs
├── Hypotheses
├── Uncertainty
├── History
└── Context
Instead of repeatedly operating on raw language, future reasoning could operate
on this evolving internal state.

🧪 RESEARCH METHOD
Every major architectural decision should follow this loop:
             ┌──────────────┐
             │   QUESTION   │
             └──────┬───────┘
                    ↓
             ┌──────────────┐
             │  HYPOTHESIS  │
             └──────┬───────┘
                    ↓
             ┌──────────────┐
             │   PROTOTYPE  │
             └──────┬───────┘
                    ↓
             ┌──────────────┐
             │  EXPERIMENT  │
             └──────┬───────┘
                    ↓
             ┌──────────────┐
             │  MEASUREMENT │
             └──────┬───────┘
                    ↓
             ┌──────────────┐
             │  OBSERVATION │
             └──────┬───────┘
                    ↓
             ┌──────────────┐
             │    REVISE    │
             └──────┬───────┘
                    │
                    └──────────► BACK TO QUESTION
No architectural idea is sacred.

🧬 REPRESENTATION RESEARCH
Current candidate approaches include:
🕸️ Structural / Semantic Graphs
🧩 Semantic Frames
📐 Distributed Representations
🧠 Hyperdimensional / Vector-Symbolic Approaches
🔗 Hybrid Representations
⚙️ Completely Custom Representation

The purpose of the prototypes is to discover what properties Spidey's
representation actually needs.

🧪 CURRENT PROTOTYPES
Prototype A
Structural Graph
[API] ──rejects──> [credentials]
          │
       possible
         cause
          ↓
   [login failure]
Prototype B
Distributed Representation
information
     ↓
numerical representation
     ↓
similarity / composition / retrieval
Prototype C
Hybrid Representation
          INFORMATION
               │
       ┌───────┴───────┐
       ▼               ▼
   STRUCTURE         VECTOR
       │               │
 relationships     similarity
 events            patterns
 states            generalization
       │               │
       └───────┬───────┘
               ▼
            SPIDEY
These are experimental prototypes, not the final architecture.

🧪 EXPERIMENTAL TRACK
Spidey's current research process includes:
LANGUAGE EXAMPLES
        ↓
INFORMATION UNITS
        ↓
REPRESENTATION EXPERIMENTS
        ↓
REPRESENTATION OPTIONS
        ↓
EVALUATION
        ↓
PROTOTYPES
        ↓
ARCHITECTURAL DECISION
The project intentionally documents failed ideas as well as successful ones.
A failed experiment is still useful information.

🛠️ TECH STACK
| Tool | Role |
|---|---|
| 🧠 **C++20** | Spidey core |
| 🔧 **GCC / MinGW-w64** | Compiler |
| 🏗️ **CMake** | Build system |
| 🐛 **GDB** | Debugging |
| 🕸️ **Git** | Version control |
| 📐 **Eigen** | Mathematics |
| 🧪 **GoogleTest** | Testing |
Experimental / Future
CUDA
GPU acceleration
additional numerical tooling
custom storage systems
Nothing gets added merely because it's fashionable.

🚫 NO PRETRAINED BRAIN
Spidey is intentionally not:
❌ A ChatGPT wrapper
❌ An API wrapper
❌ A downloaded model with a custom UI
❌ A pretrained model with a new personality
❌ A prompt-engineering project
❌ A pile of unrelated AI libraries

Infrastructure libraries are tools.
Spidey's intelligence architecture is the thing we're building.

🔒 LOCAL-FIRST
Spidey is designed around a local development environment.
The goal is to keep the core project:
LOCAL
 ↓
SELF-CONTROLLED
 ↓
EXPERIMENTABLE
 ↓
REPRODUCIBLE
Cloud services are not required for the core architecture.

🧱 PROJECT STRUCTURE
Spidey/
│
├── CMakeLists.txt
├── README.md
├── .gitignore
│
├── src/
│   ├── main.cpp
│   └── representation/
│       └── entity.cpp
│
├── include/
│   └── spidey/
│       └── representation/
│           └── entity.h
│
├── tests/
│   └── entity_test.cpp
│
├── research/
│   ├── REPRESENTATION.md
│   ├── INFORMATION_UNITS.md
│   ├── LANGUAGE_EXAMPLES.md
│   ├── REPRESENTATION_EXPERIMENTS.md
│   ├── REPRESENTATION_OPTIONS.md
│   ├── REPRESENTATION_EVALUATION.md
│   └── PROTOTYPE_PLAN.md
│
└── docs/
    └── TECHNICAL_FOUNDATION.md

🕸️ DEVELOPMENT PRINCIPLES
01 — Architecture First
Understand the problem before implementing it.
02 — Experiments Over Assumptions
A hypothesis is not a fact.
03 — Small Prototypes
Build the smallest thing that can answer the question.
04 — Everything Is Replaceable
A failed experiment is useful information.
05 — Local First
The project is designed around local development and free tooling.
06 — No Artificial Complexity
Don't add a dependency just because it exists.
07 — Preserve History
Important architectural decisions and failed experiments should remain
documented.
08 — Measure Before Optimizing
Performance optimization comes after we know where the real bottlenecks are.
