# Spidey Representation Research

## 1. Purpose

This document records research and experiments concerning how Spidey
represents information internally.

The representation system is not finalized.

No representation should be selected merely because it is common in existing
AI systems.

---

## 2. Representation Goals

A useful internal representation should be able to preserve or express:

### Meaning

What the information is about.

### Relationships

How pieces of information relate to one another.

### Roles

What function a piece of information has within a situation.

Examples:

- goal
- action
- object
- constraint
- cause
- result
- condition
- dependency
- evidence
- uncertainty

### Context

Information should be interpretable in relation to the current situation.

### State

The representation should allow information to change as Spidey learns,
reasons, receives new evidence, or completes actions.

### Focus

The system should be able to identify which information is currently
important.

### Uncertainty

The system should be able to represent incomplete knowledge, competing
possibilities, and confidence.

### Composition

Small pieces of information should be capable of forming larger structures.

### Generalization

The representation should allow similar concepts or relationships to be
recognized even when the surface wording is different.

---

## 3. Research Questions

We need to investigate:

1. What is the smallest useful unit of information for Spidey?
2. Should that unit represent text, meaning, concepts, relationships, or
   another structure?
3. Can multiple forms of information coexist in the same representation?
4. How should context be represented?
5. How should relationships be represented?
6. How should ambiguity be represented?
7. How should uncertainty be represented?
8. How should the representation change through learning?
9. How should information be retrieved by the attention system?
10. Can the representation support reasoning without requiring raw text at
    every stage?

---

## 4. Constraints

The representation system should:

- be designed specifically for Spidey's architecture
- be implementable locally
- avoid unnecessary dependencies
- be testable
- be measurable
- be replaceable if experiments disprove it

---

## 5. Current Status

Status: RESEARCH

No final encoding or representation system has been selected.

Future experiments must record:

- hypothesis
- design
- implementation
- observed behavior
- limitations
- conclusions
```

Save it.

### Why this step matters

We're separating two questions:

```text
WHAT should Spidey understand?
          ↓
HOW should Spidey represent it?
```

We're answering **WHAT** first.

Once this is saved, our next step will be to create a few **real-world language examples** and break them down manually. Those examples will become the first tests for whatever representation we eventually invent.