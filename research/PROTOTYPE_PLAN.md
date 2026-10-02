# Spidey Representation Prototype Plan

## Purpose

This document defines the first minimal prototypes for testing candidate
internal representations.

These prototypes are research experiments.

They are not intended to become the final implementation of Spidey.

The goal is to learn which properties are useful before committing to a
larger architecture.

---

# 1. Prototype A — Structural Graph

## Concept

Represent information using explicit entities, events, properties, and
relationships.

Example:

```text
[API]
  |
 rejects
  |
[credentials]

[API rejects credentials]
          |
        possible cause
          |
[login failure]
```

## Primary Question

Can an explicit structural representation preserve the information and
relationships required by Spidey?

## Prototype Requirements

The prototype should eventually be able to represent:

- entities
- states
- actions
- events
- properties
- relationships
- goals
- constraints
- evidence
- hypotheses
- uncertainty

## Operations to Test

```text
create entity
create event
create relationship
attach property
query relationship
update state
add evidence
create hypothesis
modify hypothesis
```

## Success Criteria

The prototype should make it possible to inspect and manipulate the structure
without reconstructing the original sentence.

## Known Risk

The representation may become increasingly complex as more types of
information are added.

---

# 2. Prototype B — Distributed Representation

## Concept

Represent information using numerical vectors.

Conceptually:

```text
API
    ↓
[ ... numerical representation ... ]
```

The exact vector generation mechanism is intentionally undecided.

This prototype is not a pretrained embedding model.

## Primary Question

Can numerical representations provide useful similarity and composition
while preserving enough information for Spidey's requirements?

## Prototype Requirements

The prototype should eventually allow experiments involving:

- vector creation
- similarity
- combination
- transformation
- storage
- retrieval

## Operations to Test

```text
create representation
compare representations
combine representations
retrieve similar representations
modify representation
measure representation size
```

## Success Criteria

The prototype should demonstrate whether distributed representations can
provide useful similarity and generalization while remaining compatible with
Spidey's larger architecture.

## Known Risk

Important symbolic relationships may become difficult to inspect or preserve.

---

# 3. Prototype C — Hybrid Representation

## Concept

Combine explicit structural information with a distributed numerical
representation.

Conceptually:

```text
                SITUATION
                    |
          ┌─────────┴─────────┐
          │                   │
      STRUCTURE             VECTOR
          │                   │
   relationships         similarity
   events                generalization
   states                learned patterns
          │                   │
          └─────────┬─────────┘
                    │
                 shared
                situation
```

## Primary Question

Can explicit structure and distributed representation complement one another?

## Prototype Requirements

The prototype should contain:

```text
structural representation
        +
numerical representation
```

The two representations should refer to the same underlying information.

## Operations to Test

```text
create structured information
create numerical representation
associate both representations
retrieve by structure
retrieve by similarity
update state
compare related information
```

## Success Criteria

The prototype should allow us to determine whether combining representations
provides useful capabilities that neither representation provides alone.

## Known Risk

Synchronization between representations may increase complexity.

---

# 4. Common Test Cases

All prototypes should eventually be tested against the same examples.

Primary source:

```text
research/LANGUAGE_EXAMPLES.md
```

Initial required cases:

```text
01. Fact
02. Goal
03. Constraint
04. Relationship
05. Cause and result
06. Uncertainty
07. Context
08. Ambiguity
09. Conditional requirement
10. Multi-constraint request
11. Temporal relationship
12. Correction
13. Knowledge gap
14. Conflicting information
15. Implicit intent
```

---

# 5. First Shared Experimental Scenario

All prototypes should eventually represent:

> I’m building a Django authentication API for my React app. The database
> already exists and I don’t want its schema changed. Login worked yesterday,
> but today the API returns 401. I think the token might be expired, although
> I’m not sure.

This scenario contains:

```text
goal
entities
relationships
dependency
constraint
historical state
current observation
hypothesis
uncertainty
context
```

It therefore provides a useful combined test.

---

# 6. Controlled Comparison

The three prototypes should receive the same information.

We should compare:

```text
                    SAME INPUT
                        │
          ┌─────────────┼─────────────┐
          ↓             ↓             ↓
      Prototype A    Prototype B    Prototype C
       structure       vector        hybrid
          │             │             │
          └─────────────┼─────────────┘
                        ↓
                   evaluation
```

We should not modify the test after seeing which prototype performs better.

Additional tests may be added if all three expose the same missing capability.

---

# 7. Evaluation Dimensions

Each prototype will be evaluated on:

```text
meaning preservation
relationship preservation
context handling
uncertainty handling
temporal information
belief revision
goal representation
constraint representation
dependency representation
memory support
attention support
reasoning support
learning support
generalization
ambiguity handling
evidence / provenance
representation size
memory usage
computational cost
update cost
implementation complexity
```

The detailed evaluation procedure is defined in:

```text
research/REPRESENTATION_EVALUATION.md
```

---

# 8. Prototype Rules

## Rule 1 — Minimal

Each prototype should contain only enough code to test the specific
hypothesis.

Do not build unnecessary infrastructure.

## Rule 2 — Independent

A prototype should be understandable independently of the other prototypes.

## Rule 3 — Reproducible

The same input should produce an inspectable result.

## Rule 4 — Measurable

Important operations should eventually have measurable behavior.

## Rule 5 — Replaceable

No prototype should be treated as permanent architecture.

## Rule 6 — No Pretrained Brain

The prototypes must not use a pretrained AI model as their underlying
representation.

## Rule 7 — No Premature Encoding

We are not yet defining Spidey's final language encoding system.

---

# 9. Implementation Order

The initial implementation order is:

```text
Prototype A
    ↓
Prototype B
    ↓
Prototype C
    ↓
controlled comparison
    ↓
research conclusions
```

This order is intended to establish an explicit structural baseline before
introducing distributed representations.

It is not a declaration that the structural approach will become Spidey's
final architecture.

---

# 10. Prototype Boundaries

The first prototypes should NOT implement:

```text
full natural-language understanding
full learning system
full attention system
full reasoning system
persistent user memory
personality
GUI
CUDA optimization
```

Those belong to later stages.

The prototypes exist specifically to answer the representation question.

---

# 11. What We Expect to Learn

The experiments should help answer questions such as:

```text
What information is easiest to preserve structurally?

What information is easier to represent numerically?

What information is lost when structure is compressed?

Can numerical similarity complement explicit relationships?

Can both representations be updated consistently?

Does one representation require information that the others do not?

Which operations are cheap or expensive?

What should Spidey's true internal representation contain?
```

---

# 12. Decision Gate

After the prototypes have been implemented and evaluated, we will decide whether
to:

```text
continue with one candidate
```

or:

```text
combine ideas from multiple candidates
```

or:

```text
design a new representation based on the experimental findings
```

No final architecture is selected beforehand.

---

# Current Status

Status: PROTOTYPE PLAN DEFINED

Selected for initial experimentation:

```text
Prototype A — Structural Graph
Prototype B — Distributed Representation
Prototype C — Hybrid Representation
```

Next stage:

Implement the smallest possible version of Prototype A and run it against
a controlled test case.