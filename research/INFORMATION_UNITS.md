# Spidey Information Units

## Purpose

This document identifies possible fundamental information units that Spidey
may need to represent internally.

These are hypotheses for research.

They are not a final encoding scheme, tokenizer, ontology, or implementation.

---

## 1. Entity

An entity is a thing that information refers to.

Examples:

- server
- API
- database
- user
- login system
- token
- file

Example:

> The server is running.

Possible entity:

```text
server
```

---

## 2. State

A state describes a condition or situation associated with something.

Examples:

- running
- stopped
- available
- unavailable
- expired
- broken
- working

Example:

> The server is running.

Possible state:

```text
server → running
```

---

## 3. Action

An action represents something being done or something that occurs.

Examples:

- build
- send
- reject
- change
- update
- delete
- connect

Example:

> The frontend sends requests to the API.

Possible action:

```text
send
```

---

## 4. Goal

A goal represents a desired outcome.

Example:

> I need to build a login system.

Possible structure:

```text
goal
  ├── action: build
  └── object: login system
```

---

## 5. Constraint

A constraint limits what actions are allowed.

Example:

> Do not change the database schema.

Possible structure:

```text
constraint
  ├── action: change
  └── target: database schema
  └── allowed: false
```

---

## 6. Relationship

A relationship connects pieces of information.

Examples:

```text
frontend → sends → API
credentials rejection → causes → login failure
server update → precedes → error
```

Relationships may be:

- causal
- temporal
- structural
- hierarchical
- dependent
- contradictory
- associative

---

## 7. Cause

A cause represents something that may produce or explain another event or
state.

Example:

> The login fails because the API rejects the credentials.

Possible relationship:

```text
API rejects credentials
        ↓
causes
        ↓
login failure
```

---

## 8. Result

A result represents an outcome produced by an action, event, or condition.

Example:

```text
server update
      ↓
possible result
      ↓
error
```

---

## 9. Condition

A condition specifies circumstances under which something applies.

Example:

> If the database is unavailable, show an error.

Possible structure:

```text
condition:
    database = unavailable

action:
    show error
```

---

## 10. Evidence

Evidence is information that supports or contradicts a belief, hypothesis,
or conclusion.

Example:

> The API returns 401.

This may provide evidence relevant to a login problem.

Evidence should remain distinguishable from conclusions.

---

## 11. Hypothesis

A hypothesis is a possible explanation that has not yet been established.

Example:

> I think the problem might be the session cookie.

Possible structure:

```text
hypothesis:
    session cookie is responsible

status:
    unconfirmed
```

---

## 12. Uncertainty

Uncertainty represents incomplete or unresolved knowledge.

Examples:

- unknown cause
- ambiguous reference
- incomplete evidence
- competing hypotheses
- uncertain outcome

Example:

> I don't know why the database connection keeps dropping.

Possible state:

```text
problem = known
cause = unknown
```

---

## 13. Context

Context represents information needed to interpret other information correctly.

Example:

> It works locally, but not on the server.

The meaning of "it" depends on earlier context.

Possible context:

```text
subject = previously discussed system
environment A = local
environment B = server
```

---

## 14. Reference

A reference connects an expression to something already mentioned or known.

Examples:

- it
- this
- that server
- the previous error
- the token

Example:

> It stopped working after I changed it.

The expression "it" requires resolution to an existing entity or structure.

---

## 15. Time

Temporal information represents when something happens or how events relate
in time.

Examples:

- before
- after
- during
- recently
- eventually

Example:

> The error started after the server was updated.

Possible relationship:

```text
server update
      ↓
before
      ↓
error started
```

---

## 16. Belief

A belief represents what the system currently considers to be true.

A belief should remain distinguishable from an observed fact.

Example:

```text
belief:
    API is broken
```

Later:

```text
new evidence:
    token is expired
```

The previous belief may then need to be revised.

---

## 17. Observation

An observation represents something directly received or measured.

Example:

```text
HTTP status = 401
```

An observation should not automatically become a conclusion.

Possible flow:

```text
observation
     ↓
interpretation
     ↓
hypothesis
     ↓
conclusion
```

---

## 18. Contradiction

A contradiction occurs when two pieces of information appear incompatible.

Example:

> The server says the file exists, but the application cannot find it.

Possible structure:

```text
observation A:
    file exists

observation B:
    application cannot access file

relationship:
    apparent conflict
```

---

## 19. Identity

Identity represents what makes two references refer to the same underlying
thing.

Example:

```text
"the API"
"authentication service"
"backend service"
```

These may or may not refer to the same entity depending on context.

---

## 20. Composition

Information units should be capable of combining into larger structures.

For example:

```text
Entity
   +
State
   +
Relationship
```

may form a larger situation model.

A more complex structure may contain:

```text
goal
  ├── action
  ├── object
  ├── constraints
  ├── dependencies
  └── desired result
```

---

## 21. Candidate Core Categories

For research purposes, the current candidate categories are:

```text
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
```

This list is intentionally provisional.

---

## 22. Research Rule

We should not assume that every category above requires a separate physical
representation.

Some categories may eventually be represented as:

- properties
- relationships
- states
- metadata
- structures
- learned representations
- combinations of multiple units

The implementation should follow experimental evidence rather than this
initial classification.

---

## Current Status

Status: HYPOTHESIS

The information units have been identified for further investigation.

No final internal representation has been selected.