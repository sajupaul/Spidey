# Spidey Representation Options

## Purpose

This document compares candidate approaches for Spidey's internal
representation.

No option is currently selected.

The purpose of this comparison is to identify strengths, weaknesses,
research questions, and possible combinations.

---

# 1. Candidate A — Symbolic / Semantic Graph

## Basic Idea

Represent information as nodes and relationships.

Example:

```text
[API]
  |
 rejects
  |
[credentials]

[API rejects credentials]
          |
        causes
          |
[login failure]
```

## Strengths

- Explicit relationships.
- Highly interpretable.
- Natural representation for entities and events.
- Relationships can carry their own properties.
- Useful for tracing reasoning paths.
- Can represent causal, temporal, and dependency structures.

## Weaknesses

- Constructing the graph from natural language is difficult.
- Real language can contain ambiguity and incomplete information.
- Graphs can become large and complicated.
- Purely symbolic representations may have difficulty capturing similarity
  and gradual uncertainty.

## Spidey Relevance

Very relevant to:

- structure
- relationships
- reasoning
- memory
- explainability

## Research Question

Can a graph-like structure become the foundation of Spidey's working
situation?

---

# 2. Candidate B — Semantic Frames

## Basic Idea

Represent situations using structured roles.

Example:

```text
REJECTION_EVENT

actor:
    API

object:
    credentials

result:
    rejected
```

Another example:

```text
BUILD_EVENT

actor:
    developer

action:
    build

object:
    authentication API

constraint:
    schema unchanged
```

## Strengths

- Naturally represents roles.
- Useful for events and actions.
- Can capture relationships within a situation.
- More structured than raw text.

## Weaknesses

- Requires definitions for many possible situations.
- Real language can create situations that do not fit predefined frames.
- May require increasingly complex schemas.

## Spidey Relevance

Potentially useful for:

- actions
- events
- goals
- roles
- constraints

## Research Question

Can frames be learned or created dynamically instead of requiring a
predefined frame for every situation?

---

# 3. Candidate C — Distributed Vector Representation

## Basic Idea

Represent information using numerical vectors.

Conceptually:

```text
server
   ↓
[0.12, -0.83, 0.44, ...]
```

Related concepts may occupy nearby regions of a learned space.

## Strengths

- Captures similarity.
- Can represent large amounts of information numerically.
- Suitable for mathematical optimization.
- Naturally compatible with machine learning.
- Efficient numerical operations are possible.

## Weaknesses

- Individual dimensions are often difficult to interpret.
- Explicit relationships are not naturally visible.
- Maintaining exact symbolic structure can be difficult.
- Requires careful design or learning procedures.

## Spidey Relevance

Potentially useful for:

- similarity
- generalization
- learned concepts
- pattern recognition
- neural components

## Research Question

Can distributed representations coexist with explicit structural
representations without destroying interpretability?

---

# 4. Candidate D — Hyperdimensional Computing / Vector Symbolic Architecture

## Basic Idea

Represent symbols and structures using high-dimensional distributed vectors
and operations that combine them.

Common operations in this research area include:

```text
binding
bundling
permutation
similarity
```

These approaches aim to combine properties of symbolic structure and
distributed representation.

## Strengths

- Distributed representation.
- Supports structured composition.
- Can combine multiple pieces of information.
- Provides algebraic operations over representations.
- Potentially useful for associative memory.
- Can represent information in superposition.

## Weaknesses

- Representation capacity and interference require careful analysis.
- The correct dimensionality and operations depend on the architecture.
- Not automatically equivalent to semantic understanding.
- Different VSA/HDC models have different properties.

## Spidey Relevance

Potentially useful for:

- memory
- associative retrieval
- composition
- structured distributed representations
- attention

## Research Question

Could HDC/VSA provide a mathematical layer between symbolic structure and
learned representations?

---

# 5. Candidate E — Hybrid Representation

## Basic Idea

Use multiple representation types together.

Example:

```text
                SITUATION
                    |
        ┌───────────┴───────────┐
        |                       |
   STRUCTURAL                DISTRIBUTED
   REPRESENTATION            REPRESENTATION
        |                       |
 relationships             similarity
 events                    generalization
 states                    learned patterns
        |                       |
        └───────────┬───────────┘
                    |
                REASONING
```

## Strengths

- Can preserve explicit structure.
- Can also capture similarity and learned patterns.
- Different representation types can perform different jobs.
- Potentially aligns strongly with Spidey's requirements.

## Weaknesses

- More complicated architecture.
- Requires synchronization between representations.
- More computational overhead.
- More difficult to design correctly.

## Spidey Relevance

Very high potential relevance.

## Research Question

Can Spidey use a structural representation as its core while adding
distributed representations only where they provide a measurable advantage?

---

# 6. Candidate F — Completely Custom Representation

## Basic Idea

Design a representation specifically for Spidey instead of adopting an
existing representation family.

Possible structure:

```text
SPIDEY UNIT
    |
    ├── identity
    ├── state
    ├── relations
    ├── source
    ├── confidence
    ├── time
    ├── context
    ├── importance
    └── history
```

The mathematical form could be designed later.

## Strengths

- Maximum architectural freedom.
- Can be designed around Spidey's exact requirements.
- No requirement to fit an existing representation format.
- Allows us to combine ideas discovered during research.

## Weaknesses

- Highest research risk.
- We must design and validate everything ourselves.
- Fewer existing implementations to learn from.
- Poor design could produce an inefficient system.

## Spidey Relevance

Potentially the highest architectural freedom.

## Research Question

Can we create a representation that combines explicit structure,
distributed information, uncertainty, and dynamic state without becoming
unmanageably complex?

---

# 7. Candidate Comparison

| Property | Semantic Graph | Semantic Frames | Distributed Vectors | HDC/VSA | Hybrid | Custom |
|---|---:|---:|---:|---:|---:|---:|
| Explicit relationships | High | High | Low | Medium | High | Unknown |
| Interpretability | High | High | Low | Medium | Medium/High | Unknown |
| Similarity | Low/Medium | Low/Medium | High | High | High | Unknown |
| Composition | High | High | High | High | High | Unknown |
| Uncertainty | Medium | Medium | Medium | Medium | High | Unknown |
| Memory potential | High | High | High | High | High | Unknown |
| Generalization | Medium | Medium | High | High | High | Unknown |
| Architectural freedom | Medium | Medium | Medium | Medium | High | Maximum |
| Research difficulty | Medium | Medium/High | High | High | Very High | Very High |

These ratings are initial research judgments, not measured Spidey results.

They must not be treated as final conclusions.

---

# 8. Elimination Criteria

A candidate should not be selected merely because it is popular.

We should test whether it can support:

```text
1. Meaning
2. Relationships
3. Context
4. State changes
5. Uncertainty
6. Evidence
7. Belief revision
8. Goals
9. Constraints
10. Memory
11. Attention
12. Reasoning
13. Learning
14. Generalization
```

---

# 9. Important Research Observation

Existing research suggests that structured semantic representations can provide
interpretability and explicit relational structure, while distributed
representations provide complementary information such as similarity and
generalization.

Therefore, a hybrid architecture should remain under consideration.

This does NOT mean that a hybrid architecture is automatically the correct
architecture for Spidey.

---

# 10. Current Hypotheses

### Hypothesis A

A purely symbolic representation may provide strong structure but may be
insufficient for all forms of generalization and similarity.

### Hypothesis B

A purely distributed representation may provide strong similarity and
learning capabilities but may make explicit reasoning structures harder to
inspect and manipulate.

### Hypothesis C

A hybrid representation may provide a useful balance between structure and
distributed information.

### Hypothesis D

A custom representation could potentially outperform existing approaches for
Spidey's specific goals, but this requires substantially more research and
experimentation.

---

# 11. Decision Rule

We will not select a final representation based on intuition alone.

A candidate should eventually be implemented as an experiment and evaluated
against controlled test cases.

Evaluation should measure:

- information preservation
- relationship preservation
- ambiguity handling
- uncertainty handling
- memory retrieval
- update behavior
- reasoning support
- computational cost
- scalability
- learnability

---

# Current Status

Status: COMPARISON

No representation has been selected.

Next stage:

Design small experimental implementations for multiple candidates and compare
their behavior on the Spidey language examples.