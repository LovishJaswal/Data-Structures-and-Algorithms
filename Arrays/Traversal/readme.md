# Traversal

## Core Idea

Visit every element exactly once.

Traversal is the simplest pattern where the answer can be obtained by
processing each element individually without requiring extra
preprocessing or complex data structures.

---

## Recognition Triggers

Ask yourself:

- Do I only need to inspect every element once?
- Can the answer be built while traversing?
- Does each element contribute independently?
- Is there no need for sorting or extra preprocessing?

---

## Common Observations

### Linear Scan

Process elements from left to right.

---

### Running State

Maintain variables such as:

- Count
- Maximum / Minimum
- Running Answer
- Current Position

---

### In-place Update

Modify the array directly while traversing if allowed.

---

## Problems Solved

| Problem | Key Observation |
|---------|------------------|
| Two Sum | Compare every element with previously seen values (baseline traversal idea) |
| Plus One | Traverse from the end while handling carry |
| Longest Common Prefix | Compare characters while traversing all strings |

---

## Optimization Mindset

1. Can one traversal solve the problem?
2. Avoid unnecessary nested loops.
3. Maintain only the information needed.
4. Stop early if the answer is already known.

---

## Mental Checklist

Before coding, ask:

☐ Can I solve this in one pass?

☐ Am I visiting any element unnecessarily?

☐ Can I keep a running answer?

☐ Can I modify the array in-place?

☐ Is early termination possible?

---

## Keywords

Linear Scan

One Pass

Running State

In-place Traversal

Early Exit

Iteration