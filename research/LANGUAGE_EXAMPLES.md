# Spidey Language Examples

## Purpose

These examples are initial test cases for researching Spidey's internal
representation.

They are not a final training dataset and do not define the encoding system.

---

## Example 01 — Fact

> The server is running.

Information present:

- subject: server
- state: running
- certainty: direct statement

---

## Example 02 — Goal

> I need to build a login system.

Information present:

- actor: I
- goal: build
- object: login system

---

## Example 03 — Constraint

> Do not change the database schema.

Information present:

- action: change
- object: database schema
- constraint: prohibited

---

## Example 04 — Relationship

> The frontend sends requests to the API.

Information present:

- subject: frontend
- action: sends requests
- destination: API
- relationship: frontend → API

---

## Example 05 — Cause and Result

> The login fails because the API rejects the credentials.

Information present:

- problem: login fails
- cause: API rejects credentials
- relationship: rejected credentials → login failure

---

## Example 06 — Uncertainty

> I think the problem might be the session cookie.

Information present:

- subject: problem
- hypothesis: session cookie
- uncertainty: possible, not confirmed

---

## Example 07 — Context

> It works locally, but not on the server.

Information present:

- environment A: local
- environment B: server
- state in A: works
- state in B: does not work
- contrast: local ≠ server

---

## Example 08 — Ambiguity

> It stopped working after I changed it.

Information present:

- subject: it
- state change: stopped working
- previous event: changed it
- unresolved reference: "it"
- unresolved actor/object of "changed"

---

## Example 09 — Conditional Requirement

> If the database is unavailable, show an error instead of retrying forever.

Information present:

- condition: database unavailable
- action: show error
- prohibited behavior: infinite retry
- dependency: database availability → response behavior

---

## Example 10 — Multi-Constraint Request

> Build the authentication API in Django, use the existing database, and
> don't modify the schema.

Information present:

- goal: build authentication API
- implementation technology: Django
- resource: existing database
- constraint: database schema immutable
- relationships:
  - authentication API → Django
  - authentication API → existing database

---

## Example 11 — Temporal Relationship

> The error started after the server was updated.

Information present:

- event A: server updated
- event B: error started
- temporal relationship: A occurred before B
- possible causal relationship: A may have contributed to B

---

## Example 12 — Correction

> I thought the API was broken, but the real problem was the expired token.

Information present:

- previous belief: API broken
- revised belief: expired token
- correction: previous belief rejected
- evidence/result: expired token identified

---

## Example 13 — Knowledge Gap

> I don't know why the database connection keeps dropping.

Information present:

- problem: database connection drops
- knowledge state: unknown cause
- uncertainty: unresolved

---

## Example 14 — Conflicting Information

> The server says the file exists, but the application cannot find it.

Information present:

- source A: server reports file exists
- source B: application cannot find file
- conflict: existence claim ≠ application access
- unresolved question: why the observations differ

---

## Example 15 — Implicit Intent

> Can you figure out why this login isn't working?

Information present:

- request type: investigation
- subject: login
- problem: login failure
- desired outcome: identify cause
- implicit action: analyze evidence and reason about possible causes

---

## Initial Test Criteria

A future representation system should be evaluated on whether it can preserve
the important information contained in these examples.

The goal is not merely to reproduce the original sentences.

The goal is to preserve enough structure to support:

- interpretation
- relationships
- attention
- reasoning
- uncertainty
- memory
- learning
- action