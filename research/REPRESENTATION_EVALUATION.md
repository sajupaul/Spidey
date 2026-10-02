# Spidey Representation Evaluation

## Purpose

This document defines how candidate internal representations will be
evaluated.

The purpose is not to select a representation immediately.

The purpose is to establish repeatable experiments that allow different
representations to be compared against the same requirements.

---

# 1. Evaluation Principles

Candidate representations must be evaluated through experiments.

A representation should not be selected solely because:

- it is popular
- it is easy to implement
- it is used by existing AI systems
- it produces visually interesting structures
- it performs well on only one type of example

A representation should be evaluated according to how well it supports the
requirements of Spidey.

---

# 2. Primary Evaluation Areas

## 2.1 Meaning Preservation

Can the representation preserve the important meaning contained in the
original input?

Test examples:

- simple facts
- goals
- technical statements
- actions
- states

---

## 2.2 Relationship Preservation

Can the representation preserve relationships between pieces of information?

Required relationship types may include:

```text
causal
temporal
structural
dependency
contradictory
associative
```

Example:

```text
API rejects credentials
        ↓
possible cause
        ↓
login failure
```

---

## 2.3 Context Preservation

Can information be interpreted correctly using surrounding or previous
context?

Example:

```text
The API is running on port 8080.
It returns 401 errors.
```

The representation should allow `"It"` to potentially resolve to the API.

---

## 2.4 Uncertainty Representation

Can the representation preserve incomplete or uncertain information?

Example:

```text
possible cause:
    expired token

status:
    unconfirmed
```

A representation should not automatically convert uncertainty into fact.

---

## 2.5 Temporal Representation

Can the representation preserve:

- ordering
- timestamps
- duration
- changing states
- historical relationships

Example:

```text
server working
      ↓
server update
      ↓
server returns 500
```

Temporal sequence should remain distinguishable from causation.

---

## 2.6 Belief Revision

Can the representation preserve a belief and later modify that belief when
new evidence appears?

Example:

```text
initial belief:
    API is broken

new observation:
    token is expired

revised belief:
    API failure may be explained by expired token
```

The previous state should not necessarily be erased.

---

## 2.7 Goal Representation

Can the representation preserve a desired outcome?

Example:

```text
goal:
    build authentication API
```

The goal should remain distinguishable from an observed fact.

---

## 2.8 Constraint Representation

Can the representation preserve restrictions on possible actions?

Example:

```text
constraint:
    database schema must not change
```

The constraint must be available to future planning and reasoning.

---

## 2.9 Dependency Representation

Can the representation preserve dependencies between components, actions,
events, or resources?

Example:

```text
React frontend
      ↓
Django API
      ↓
database
```

---

## 2.10 Memory Support

Can the representation support persistent information without reducing
memory to a raw conversation transcript?

It should be possible to distinguish candidate memory types such as:

```text
fact
decision
preference
experience
lesson
belief
goal
project state
```

---

## 2.11 Attention Support

Can the representation provide useful information to an attention mechanism?

Potentially relevant information includes:

```text
current goal
current task
relevant relationships
uncertainty
recent changes
supporting evidence
constraints
relevant memories
```

The evaluation should determine whether the representation makes useful
attention possible.

---

## 2.12 Reasoning Support

Can the representation support operations such as:

```text
comparison
inference
hypothesis generation
cause analysis
planning
contradiction detection
belief revision
```

The representation does not need to perform reasoning by itself.

It must provide a structure that reasoning can operate on.

---

## 2.13 Learning Support

Can the representation change when Spidey receives new information or
experience?

A candidate should be examined for:

- modification
- extension
- correction
- generalization
- revision
- reinforcement

---

## 2.14 Generalization

Can similar meanings or structures be recognized even when their wording
changes?

Example:

```text
"The API rejected my credentials."

"The backend refused the login credentials."
```

These sentences use different surface language but may describe related
situations.

---

## 2.15 Ambiguity Handling

Can the representation preserve ambiguity when the correct interpretation
cannot yet be determined?

Example:

```text
"It stopped working."
```

Possible unresolved reference:

```text
it
 ├── candidate A
 └── candidate B
```

The system should be allowed to delay commitment.

---

## 2.16 Evidence and Provenance

Can the representation maintain where information came from?

Potential sources include:

```text
user statement
observation
measurement
memory
derived inference
external source
```

Evidence should remain distinguishable from conclusions.

---

# 3. Evaluation Outcomes

Each experiment should use qualitative outcomes initially:

```text
PASS
PARTIAL
FAIL
NOT TESTED
```

### PASS

The representation preserves the required information with no major
architectural problem identified.

### PARTIAL

The representation preserves some important information but requires
additional mechanisms or has significant limitations.

### FAIL

The representation cannot adequately preserve or manipulate the required
information within the tested design.

### NOT TESTED

The capability has not yet been experimentally evaluated.

---

# 4. Quantitative Measurements

Where practical, experiments should also record measurable values.

Possible measurements include:

```text
information retained
relationship recovery
reference resolution
memory retrieval accuracy
update accuracy
inference consistency
computational time
memory usage
representation size
```

Numbers should only be recorded when the measurement procedure is defined.

---

# 5. Standard Test Set

Candidate representations should eventually be tested against the examples in:

```text
research/LANGUAGE_EXAMPLES.md
```

Additional experiments may be added when the existing examples reveal a
missing capability.

---

# 6. Evaluation Procedure

For each candidate representation:

```text
1. Define the representation.
2. Implement the smallest useful prototype.
3. Encode the same test examples.
4. Inspect what information is preserved.
5. Run controlled operations.
6. Record limitations.
7. Measure relevant performance.
8. Record PASS / PARTIAL / FAIL.
9. Identify architectural consequences.
10. Decide whether another experiment is required.
```

---

# 7. No Premature Selection

A candidate should not be selected because it performs well on a single
experiment.

Important failures should remain documented.

A representation that succeeds in one area but fails in another should retain
its complete experimental history.

---

# 8. Combination Experiments

Some candidates may work better when combined.

Potential combinations include:

```text
structural + distributed
symbolic + vector
graph + hyperdimensional
custom core + learned component
```

Combined approaches must be evaluated as systems rather than assuming that
their individual strengths automatically combine.

---

# 9. Complexity

A representation should also be evaluated for implementation and operational
complexity.

Important questions:

```text
How difficult is it to construct?

How difficult is it to update?

How difficult is it to search?

How difficult is it to inspect?

How much memory does it require?

How does complexity grow as information increases?
```

---

# 10. Scalability

Small examples are necessary but insufficient.

Future experiments should progressively test:

```text
single statement
        ↓
multiple statements
        ↓
multi-step situation
        ↓
long interaction
        ↓
persistent knowledge
        ↓
large knowledge structure
```

The goal is to determine whether the representation remains useful as
information increases.

---

# 11. Research Record

Each future representation experiment should record:

```text
candidate
hypothesis
test case
representation
operations
observations
measurements
limitations
result
next question
```

---

# 12. Decision Evidence

When a representation is eventually considered for Spidey's architecture,
the decision should be supported by:

- experimental results
- measured behavior
- documented limitations
- implementation requirements
- computational requirements

The final decision should remain reversible until sufficient evidence exists.

---

# 13. Current Evaluation Matrix

| Capability | Status |
|---|---|
| Meaning preservation | NOT TESTED |
| Relationship preservation | NOT TESTED |
| Context preservation | NOT TESTED |
| Uncertainty representation | NOT TESTED |
| Temporal representation | NOT TESTED |
| Belief revision | NOT TESTED |
| Goal representation | NOT TESTED |
| Constraint representation | NOT TESTED |
| Dependency representation | NOT TESTED |
| Memory support | NOT TESTED |
| Attention support | NOT TESTED |
| Reasoning support | NOT TESTED |
| Learning support | NOT TESTED |
| Generalization | NOT TESTED |
| Ambiguity handling | NOT TESTED |
| Evidence / provenance | NOT TESTED |
| Scalability | NOT TESTED |
| Computational efficiency | NOT TESTED |

These statuses describe the evaluation program, not the quality of any
candidate representation.

---

# Current Status

Status: EVALUATION FRAMEWORK DEFINED

Candidate representations have not yet been experimentally implemented.

The next stage is to choose a small number of candidate representations and
build minimal prototypes for controlled comparison.