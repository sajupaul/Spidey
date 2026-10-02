# Spidey Representation Experiments

## Experiment 001 — Causal Technical Statement

### Input

> The login fails because the API rejects the credentials.

---

## Objective

Determine whether our candidate information units are sufficient to represent
the important structure of this sentence.

---

## Candidate Representation

### Entities

```text
login
API
credentials
```

### Actions

```text
fails
rejects
```

### Event Structures

```text
Event A:
    API rejects credentials

Event B:
    login fails
```

### Relationship

```text
Event A
   ↓
cause
   ↓
Event B
```

### Combined Structure

```text
[API] --rejects--> [credentials]
          │
          │ causes
          ↓
       [login]
          │
        fails
```

---

## Information Preserved

The representation preserves:

- entities
- actions
- event structure
- causal relationship
- relationship between API, credentials, and login failure

---

## Information Potentially Lost

The representation does not yet specify:

1. Whether the causal relationship is certain or inferred.
2. What "rejects" specifically means.
3. Which authentication mechanism is involved.
4. Whether alternative causes exist.
5. What evidence supports the causal claim.
6. Whether the statement is an observation, belief, hypothesis, or conclusion.
7. When the events occurred.
8. Whether "login" refers to a particular application or authentication
   process.

---

## Questions Raised

### Question 1

Should a relationship itself have properties?

For example:

```text
cause
    certainty = ?
    evidence = ?
    source = ?
```

### Question 2

Should an action be represented only as a label, or should it contain
additional structure?

For example:

```text
reject
    actor = API
    object = credentials
    reason = ?
```

### Question 3

Should events be first-class structures rather than combinations of
entities and actions?

### Question 4

How should Spidey distinguish:

```text
observed cause
possible cause
believed cause
confirmed cause
```

### Question 5

How should multiple possible causes coexist?

Example:

```text
login failure
    ├── possible cause → rejected credentials
    ├── possible cause → expired session
    └── possible cause → server configuration
```

---

## Preliminary Observation

The candidate information units can describe the basic structure of the
sentence, but they are not yet sufficient to describe all of the information
that may matter for reasoning.

In particular, relationships may need internal structure of their own.

This is an observation from the experiment, not a final architectural
decision.

---

## Status

Experiment result: PARTIAL

Next experiment should test whether the proposed representation can handle
uncertainty and competing hypotheses.

---

# Experiment 002 — Uncertainty and Competing Hypotheses

## Input

> I think the problem might be the session cookie, but it could also be an expired token.

---

## Objective

Determine whether our candidate representation can represent:

- uncertainty
- multiple possible explanations
- different confidence levels
- the distinction between a hypothesis and a fact
- relationships between hypotheses and the same problem

---

## Candidate Representation

### Problem

```text id="d7itgl"
problem
    identity = unknown
    state = login failure
```

### Hypothesis A

```text id="6x1dl4"
hypothesis A
    possible cause = session cookie
    status = unconfirmed
```

### Hypothesis B

```text id="xq7k9y"
hypothesis B
    possible cause = expired token
    status = unconfirmed
```

### Relationship to Problem

```text id="in8med"
session cookie
      ↓
possible cause
      ↓
login failure


expired token
      ↓
possible cause
      ↓
login failure
```

---

## Combined Structure

```text id="7n1ek5"
                    [LOGIN FAILURE]
                    /              \
                   /                \
          possible cause      possible cause
                 /                    \
                ↓                      ↓
       [SESSION COOKIE]         [EXPIRED TOKEN]
              │                        │
         unconfirmed              unconfirmed
```

---

## Information Preserved

The representation preserves:

- the existence of a problem
- multiple possible causes
- the distinction between possible causes and confirmed facts
- relationships between causes and the problem
- the fact that the causes compete as explanations

---

## Information Potentially Lost

The representation does not yet specify:

1. How strong each hypothesis is.
2. Why each hypothesis exists.
3. What evidence supports each hypothesis.
4. Whether the hypotheses are mutually exclusive.
5. Whether both causes could be true simultaneously.
6. How new evidence should change their confidence.
7. How Spidey should decide what hypothesis to investigate first.
8. Whether confidence should be numerical, categorical, or another form.

---

## New Observation

Uncertainty appears to be more than a single property attached to a piece of
information.

A hypothesis may need its own state containing:

```text id="2h0v9y"
hypothesis
    ├── proposed explanation
    ├── supporting evidence
    ├── contradicting evidence
    ├── confidence
    ├── alternatives
    └── current status
```

This suggests that some information structures may need to be treated as
dynamic objects rather than static labels.

---

## Attention Implication

If multiple hypotheses exist, Spidey's attention system may need to consider:

```text id="bzmv48"
importance
+
evidence strength
+
uncertainty
+
current goal
+
cost of investigation
```

Therefore, attention may need access to the structure of the information,
not merely its position in the input.

This is a hypothesis for future investigation.

---

## Learning Implication

Suppose new evidence appears:

```text id="e3azx4"
session cookie = valid
```

The system should be able to update the hypothesis state:

```text id="t9v2v0"
session cookie hypothesis
    confidence ↓
```

without destroying the entire representation.

Likewise:

```text id="8ro3wq"
token = expired
```

could increase the relevance of the expired-token hypothesis.

---

## Result

Experiment result: PARTIAL

The candidate representation can express competing hypotheses and
uncertainty, but it does not yet define how confidence, evidence, attention,
or belief revision should work.

---

## Status

More research required.

Next experiment should test temporal information, context, and changing state.

---

# Experiment 003 — Temporal State Change

## Input

> The server was working yesterday, but after the update it is returning 500 errors.

---

## Objective

Determine whether the candidate representation can preserve:

- time
- changing state
- events
- sequence
- context
- possible causal relationships
- the distinction between temporal sequence and proven causation

---

## Candidate Representation

### State A

```text
entity = server
time = yesterday
state = working
```

### Event

```text
event = server update
```

### State B

```text
entity = server
time = after update
state = returning 500 errors
```

---

## Temporal Structure

```text
[yesterday]
server
   │
   └── state = working
          │
          ↓
      server update
          │
          ↓
[after update]
server
   │
   └── state = 500 errors
```

---

## Important Distinction

The representation establishes:

```text
server update
        ↓
occurred before
        ↓
500 errors
```

It does **not** automatically establish:

```text
server update
        ↓
caused
        ↓
500 errors
```

Causation would require additional evidence.

---

## Information Preserved

The representation preserves:

- entity identity
- earlier state
- later state
- event ordering
- temporal context
- state transition
- distinction between sequence and causation

---

## Information Potentially Lost

The representation does not yet specify:

1. Exact timestamps.
2. Duration of each state.
3. Whether the server changed continuously or suddenly.
4. Evidence connecting the update to the errors.
5. Whether other events occurred between the update and the errors.
6. Whether "the update" refers to software, configuration, or another change.

---

## New Observation

A useful representation may need to treat state as something that can change
through time rather than as a permanent property.

Possible abstraction:

```text
entity
   ↓
state
   ↓
time
   ↓
transition
   ↓
new state
```

---

## Result

Experiment result: PARTIAL

The candidate representation can describe the sequence of states and events,
but temporal detail and causal inference remain undefined.

---

## Status

More research required.

Next experiment should test whether context and references can be resolved
across multiple statements.

---

# Experiment 004 — Context and Reference Resolution

## Input

> The API is running on port 8080. It returns 401 errors. I changed it yesterday, but it worked before that.

---

## Objective

Determine whether the candidate representation can preserve:

- context across multiple statements
- references to previously mentioned information
- temporal relationships
- identity across different expressions
- state changes
- unresolved or ambiguous references

---

## Statement 1

```text id="0x2m7q"
entity = API
state = running
property:
    port = 8080
```

---

## Statement 2

```text id="8v8tqp"
reference = "It"
resolved candidate = API

action = returns
result = 401 error
```

The word `"It"` cannot be interpreted independently.

Its meaning depends on the previous context.

---

## Statement 3

```text id="qy5u5c"
actor = I
action = changed
object = API
time = yesterday
```

The expression `"it"` is interpreted using the previously established
context.

---

## Statement 4

```text id="3h8l6r"
reference = "it"
resolved candidate = API

state = worked
time = before change
```

The expression `"that"` refers to the earlier change event.

---

## Combined Structure

```text id="qv2vkk"
                [API]
                  │
        ┌─────────┼─────────┐
        │         │         │
     running   returns   changed
        │         │         │
    port 8080    401     yesterday
                            │
                            ↓
                       [previous state]
                            │
                          worked
```

Temporal relationship:

```text id="tzvct9"
API worked
    ↓
API changed
    ↓
API returns 401
```

---

## Information Preserved

The representation can preserve:

- identity of the API
- API state
- port information
- error result
- change event
- temporal ordering
- references to previously established entities/events

---

## Information Potentially Lost

The representation does not yet specify:

1. How references are resolved.
2. What happens when multiple entities could match `"it"`.
3. How long a reference remains available in context.
4. Whether a reference can point to an event rather than an entity.
5. How ambiguous references should be represented.
6. Whether context should be stored permanently or temporarily.
7. How old context should affect attention.
8. Whether the previous working state is a direct observation or an inferred
   state.

---

## New Observation

Context appears to be an active part of representation rather than simply a
container surrounding the representation.

A reference may require a lookup such as:

```text id="q9gdr8"
reference
    ↓
candidate meanings
    ↓
context
    ↓
identity / relationships
    ↓
resolved meaning
```

The resolution process may itself require uncertainty.

For example:

```text id="b5c2xn"
"it"
 ├── candidate = API
 │      confidence = high
 │
 └── candidate = database
        confidence = low
```

The system should not be forced to select a meaning when evidence is
insufficient.

---

## Attention Implication

Reference resolution may require access to previous information.

Therefore attention may eventually need to retrieve:

- recent information
- related information
- entities
- events
- prior states
- unresolved references

rather than simply examining the latest input.

---

## Result

Experiment result: PARTIAL

The candidate representation can describe the contextual relationships, but
reference resolution and ambiguity handling remain undefined.

---

## Status

More research required.

Next experiment should test contradictory evidence and belief revision.

---

# Experiment 005 — Contradictory Evidence and Belief Revision

## Input

> I thought the API was broken, but after checking the logs, I found that the
> token had expired.

---

## Objective

Determine whether the candidate representation can preserve:

- an initial belief
- new evidence
- contradiction
- belief revision
- the reason for revision
- the distinction between belief and observation
- historical state

---

## Initial Belief

```text id="0hxwt2"
belief:
    API = broken

status:
    current belief

source:
    previous reasoning
```

This is a belief, not an established fact.

---

## New Investigation

```text id="w9j1z3"
action:
    check logs
```

The investigation produces new information.

---

## Observation

```text id="7m9l5q"
observation:
    token = expired

source:
    logs
```

This should be treated as an observation/evidence item rather than
immediately replacing every previous belief.

---

## Belief Revision

```text id="tw2qte"
previous belief:
    API = broken

new evidence:
    token = expired

revised interpretation:
    expired token may explain login failure

previous belief status:
    weakened
```

---

## Combined Structure

```text
            [INITIAL BELIEF]
             API is broken
                    │
                    ↓
             [INVESTIGATION]
                check logs
                    │
                    ↓
              [OBSERVATION]
              token expired
                    │
                    ↓
           [BELIEF REVISION]
                    │
                    ↓
       API broken ← weakened
                    │
                    +
       expired token ← supported
```

---

## Important Distinction

The representation should distinguish:

```text
OBSERVATION
    ↓
what was directly discovered


BELIEF
    ↓
what Spidey currently accepts as likely true


HYPOTHESIS
    ↓
possible explanation


CONCLUSION
    ↓
result of reasoning from available information
```

These should not automatically collapse into one category.

---

## Information Preserved

The candidate representation can preserve:

- initial belief
- investigation
- new observation
- relationship between evidence and belief
- revised interpretation
- previous belief history

---

## Information Potentially Lost

The representation does not yet specify:

1. How much a piece of evidence should change a belief.
2. Whether beliefs have numerical confidence.
3. How multiple pieces of evidence combine.
4. How contradictory evidence is weighted.
5. Whether old beliefs should be retained permanently.
6. How Spidey should distinguish a belief becoming weaker from becoming false.
7. How evidence reliability should be represented.
8. How conclusions should be justified later.

---

## New Observation

A useful representation may require information to have a history.

Instead of:

```text
API = broken
```

Spidey may eventually need something closer to:

```text
belief
    ├── proposition
    ├── confidence
    ├── supporting evidence
    ├── contradicting evidence
    ├── source
    ├── timestamp
    └── revision history
```

This would allow Spidey to change its internal beliefs without erasing the
reasoning history that caused the change.

---

## Reasoning Implication

Belief revision suggests that reasoning is not necessarily a one-time process.

A possible cycle is:

```text
information
    ↓
interpretation
    ↓
belief / hypothesis
    ↓
new evidence
    ↓
revision
    ↓
new reasoning
```

---

## Attention Implication

When new evidence arrives, attention may need to prioritize information that
is directly relevant to existing beliefs or hypotheses.

For example:

```text
new observation:
    token expired

related structures:
    login failure
    authentication
    API rejection
```

---

## Result

Experiment result: PARTIAL

The candidate representation can describe belief revision conceptually, but
confidence, evidence weighting, source reliability, and revision mechanics
remain undefined.

---

## Status

More research required.

Next experiment should test multi-step goals, dependencies, and planning.

---

# Experiment 006 — Goals, Dependencies, and Planning

## Input

> Build a login system. The database already exists, the schema must not
> change, and the React frontend needs to communicate with a Django API.

---

## Objective

Determine whether the candidate representation can preserve:

- goals
- constraints
- existing resources
- system components
- dependencies
- relationships between components
- requirements for future actions
- information useful for planning

---

## Goal

```text id="2r0q1m"
goal:
    action = build
    object = login system
```

---

## Existing Resource

```text id="v0d2gp"
entity:
    database

state:
    already exists
```

---

## Constraint

```text id="6n0gu2"
constraint:
    target = database schema
    action = change
    allowed = false
```

---

## System Components

```text id="x8rxbe"
component A:
    React frontend

component B:
    Django API

component C:
    existing database
```

---

## Dependency Structure

```text id="0u13d8"
React frontend
      │
      │ communicates with
      ↓
Django API
      │
      │ communicates with
      ↓
Existing database
```

---

## Planning Implication

A possible plan derived from the structure could contain:

```text id="pk7q7m"
1. Inspect existing database structure.
2. Determine authentication requirements.
3. Design Django API interactions.
4. Implement authentication logic without changing the schema.
5. Connect the React frontend to the API.
6. Test authentication behavior.
```

This plan is not part of the input.

It is a possible result of reasoning over the represented information.

---

## Important Distinction

The representation should distinguish between:

```text id="q7tvdh"
INPUT INFORMATION
        ↓
what the user actually stated


INFERRED STRUCTURE
        ↓
relationships that can be derived


PLAN
        ↓
actions Spidey proposes
```

A proposed plan should not automatically become a fact.

---

## Information Preserved

The representation preserves:

- desired outcome
- existing resources
- constraints
- system components
- dependencies
- implementation relationships

---

## Information Potentially Lost

The representation does not yet specify:

1. Which task must happen first.
2. Which tasks can happen in parallel.
3. Which dependencies are mandatory.
4. What resources each task requires.
5. How much confidence Spidey has in a proposed plan.
6. How a failed step changes the plan.
7. How new information changes the dependency graph.
8. How Spidey chooses between multiple valid plans.

---

## New Observation

A goal appears to naturally produce a structure containing:

```text id="k6a2os"
GOAL
 ├── desired result
 ├── constraints
 ├── available resources
 ├── dependencies
 ├── possible actions
 └── success conditions
```

This suggests that planning may operate on a structured representation rather
than directly on the original sentence.

---

## Attention Implication

For a multi-step task, attention may need to prioritize:

```text id="q2t6fm"
current goal
   +
current task
   +
blocking dependency
   +
relevant constraint
   +
new evidence
```

This could allow attention to change as the workflow progresses.

---

## Reasoning Implication

A possible reasoning cycle is:

```text id="l6d6ap"
understand goal
      ↓
identify constraints
      ↓
identify dependencies
      ↓
generate possible actions
      ↓
select next action
      ↓
observe result
      ↓
update internal state
      ↓
continue or revise plan
```

This is a hypothesis for future architectural work.

---

## Result

Experiment result: PARTIAL

The candidate information units can describe the basic structure of goals,
constraints, and dependencies, but planning, prioritization, parallelism,
and adaptation remain undefined.

---

## Status

More research required.

Next experiment should test whether the representation can combine several
conversations or events into a persistent knowledge structure.

---

# Experiment 007 — Persistent Knowledge and Memory

## Input

### Event 1

> My backend uses Django.

### Event 2

> We decided yesterday not to modify the database schema.

### Later interaction

> What backend am I using, and what was our database decision?

---

## Objective

Determine whether the candidate representation can distinguish:

- immediate context
- persistent memory
- facts
- decisions
- preferences
- experiences
- temporary state
- memory retrieval
- memory relevance

---

## Memory Candidate A — Technical Fact

```text id="lbp52z"
entity:
    backend

property:
    technology = Django

memory type:
    technical fact
```

---

## Memory Candidate B — Decision

```text id="p2y9cc"
decision:
    database schema must not be modified

time:
    yesterday

memory type:
    project decision
```

---

## Immediate Context

During the current conversation, Spidey may have temporary information such
as:

```text id="uv4l1x"
current problem
current question
current task
current hypotheses
current workflow step
```

This information may not need to become permanent memory.

---

## Possible Memory Structure

```text id="vp3yqs"
MEMORY
 ├── content
 ├── type
 ├── source
 ├── time
 ├── confidence
 ├── relationships
 ├── importance
 ├── usage history
 └── revision history
```

---

## Retrieval

When the later question arrives:

> What backend am I using?

Spidey should retrieve information related to:

```text id="4v0i3g"
backend
technology
Django
```

For the second question:

> What was our database decision?

Spidey should retrieve:

```text id="n9j8a4"
database
schema
decision
not modify
```

---

## Important Distinction

Memory should not simply be:

```text id="m72uqi"
conversation history = forever
```

Instead, memory should represent information according to its role and
usefulness.

Possible categories include:

```text id="3c3r0y"
FACT
DECISION
PREFERENCE
EXPERIENCE
LESSON
BELIEF
GOAL
PROJECT STATE
```

These are only candidate categories.

---

## Memory Revision

Suppose later the user says:

> We changed our decision. The schema can now be modified.

The previous memory should not simply disappear.

Possible structure:

```text id="x8xv7a"
old decision
    ↓
superseded by
    ↓
new decision
```

This preserves history while allowing the current state to change.

---

## Memory Relevance

Not all memories should receive equal attention.

For example:

```text id="9xrs6c"
current project decision
        ↑
    high relevance

old unrelated conversation
        ↑
    low relevance
```

This suggests that memory retrieval and attention may eventually interact.

---

## New Observation

Memory may be better understood as a collection of structured information
with relationships and history rather than as a simple text archive.

Possible relationship:

```text id="jtk2q0"
MEMORY
   ↓
retrieved because relevant
   ↓
WORKING STATE
   ↓
ATTENTION
   ↓
REASONING
```

---

## Questions Raised

1. How does Spidey decide what deserves long-term memory?
2. How are memories indexed?
3. How are related memories discovered?
4. How does Spidey handle conflicting memories?
5. How does memory decay or become less relevant?
6. How does a memory gain importance through repeated use?
7. How does Spidey distinguish a user statement from an independently
   established fact?
8. How should memory be corrected without losing history?
9. Should memory be represented as a graph, hierarchy, records, vectors, or
   another structure?
10. How tightly should memory interact with attention?

---

## Result

Experiment result: PARTIAL

The candidate representation can describe persistent information and
distinguish it conceptually from temporary context, but memory formation,
retrieval, prioritization, conflict resolution, and revision remain
undefined.

---

## Status

More research required.

Next experiment should test whether one representation can combine language,
knowledge, uncertainty, memory, and goals into a single working situation.

---

# Experiment 008 — Complete Working Situation

## Input

> I’m building a Django authentication API for my React app. The database
> already exists and I don’t want its schema changed. Login worked yesterday,
> but today the API returns 401. I think the token might be expired, although
> I’m not sure.

---

## Objective

Determine whether the candidate information units can be combined into a
single working situation containing:

- goal
- entities
- relationships
- constraints
- historical states
- current observations
- hypotheses
- uncertainty
- context
- dependencies

---

## Goal

```text id="v7r6o4"
goal:
    action = build
    object = authentication API
```

---

## Entities

```text id="m8p0do"
React application
Django API
database
login
token
```

---

## Structural Relationships

```text id="b8pg0b"
React application
       │
       │ communicates with
       ↓
Django API
       │
       │ uses
       ↓
database
```

---

## Constraint

```text id="yuf9r0"
database schema
    ↓
must not change
```

---

## Historical State

```text id="rswjc2"
time = yesterday

login
    ↓
worked
```

---

## Current Observation

```text id="39lj60"
time = today

Django API
    ↓
returns
    ↓
HTTP 401
```

This should be represented as an observation rather than automatically being
interpreted as a confirmed cause.

---

## Hypothesis

```text id="ud6gxo"
possible cause:
    expired token

status:
    unconfirmed

certainty:
    unknown
```

---

## Working Situation

```text id="2su1j1"
                    [CURRENT SITUATION]
                           │
        ┌──────────────────┼──────────────────┐
        │                  │                  │
       GOAL            CONSTRAINT          HISTORY
        │                  │                  │
 auth API              schema fixed     login worked
        │                                  yesterday
        ↓                                      │
  React → Django                              ↓
        ↓                              current failure
    database                                  │
                                                ↓
                                             HTTP 401
                                                │
                                                ↓
                                      possible cause:
                                       expired token
                                                │
                                                ↓
                                          unconfirmed
```

---

## Information Types

The situation contains several distinct information types:

```text
GOAL
    build authentication API

FACT / STATE
    database already exists

CONSTRAINT
    schema must not change

RELATIONSHIP
    React → Django → database

HISTORICAL STATE
    login worked yesterday

OBSERVATION
    API returns HTTP 401 today

HYPOTHESIS
    token may be expired

UNCERTAINTY
    cause not confirmed
```

---

## What This Structure Allows

If the representation is sufficiently expressive, future systems could operate
on the situation without needing to repeatedly interpret the entire original
sentence.

For example, a reasoning system could ask:

```text
What changed between yesterday and today?

What evidence supports the expired-token hypothesis?

What other explanations could produce HTTP 401?

Which investigation should happen first?

Which actions are forbidden by the database constraint?
```

These are reasoning questions.

They should not be hardcoded as answers.

---

## Critical Observation

The representation is beginning to resemble a **dynamic state model** rather
than a text representation.

Possible abstraction:

```text
WORKING SITUATION
    ├── entities
    ├── states
    ├── events
    ├── relationships
    ├── goals
    ├── constraints
    ├── observations
    ├── beliefs
    ├── hypotheses
    ├── uncertainty
    ├── history
    └── context
```

---

## Important Architectural Question

If all of these structures coexist, we need to determine whether they should
be represented as:

```text
one unified structure
```

or:

```text
multiple specialized structures
```

or:

```text
a core structure with specialized properties
```

This is not decided by the experiment.

---

## Attention Implication

A complete situation provides the attention system with multiple dimensions
that could influence relevance.

Possible factors include:

```text
current goal
current workflow stage
relationship to active problem
uncertainty
recent changes
supporting evidence
constraints
memory relevance
```

The exact attention mechanism remains undecided.

---

## Reasoning Implication

Reasoning could potentially operate on the situation model rather than directly
on raw language.

Possible flow:

```text
language
   ↓
representation
   ↓
working situation
   ↓
attention
   ↓
reasoning
   ↓
updated situation
```

This remains a research hypothesis.

---

## Result

Experiment result: PROMISING BUT INCOMPLETE

The candidate information units can be combined into a coherent working
situation.

However, this experiment does not yet prove that the structure is optimal,
efficient, learnable, or suitable for implementation.

---

## Major Questions Now Raised

1. What is the actual fundamental representation?
2. Which structures should be persistent?
3. Which structures should be temporary?
4. How are relationships encoded?
5. How are states updated?
6. How does attention traverse the situation?
7. How does learning modify the representation?
8. How can the representation scale to large amounts of information?
9. How does language map into the representation?
10. Can the representation be learned rather than manually constructed?

---

## Status

Candidate working-situation model established.

The next research stage is to investigate **how language could be transformed
into this kind of structure without relying on a conventional token-based
representation**.