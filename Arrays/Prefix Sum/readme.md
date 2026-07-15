# Prefix Sum

## Core Idea

Precompute cumulative sums so that repeated range sum calculations
can be answered in constant time.

Spend O(n) once to save time later.

---

## Recognition Triggers

Ask yourself:

- Am I calculating the same sum repeatedly?
- Are there multiple range sum queries?
- Can previous computations be reused?
- Can preprocessing simplify the problem?

---

## Common Observations

### Running Sum

Each prefix stores the sum of all elements from the beginning of the
array up to the current index.

---

### Range Sum

Any subarray sum can be obtained by subtracting two prefix sums.

---

### Preprocessing

Do one O(n) traversal first, then answer every query in O(1).

---

## Optimization Mindset

1. Identify repeated calculations.
2. Precompute once.
3. Reuse the precomputed information.
4. Replace repeated traversal with subtraction.

---

## Mental Checklist

Before coding, ask:

☐ Am I recalculating the same sum?

☐ Can preprocessing help?

☐ Can I answer queries using subtraction?

☐ Have I handled boundary cases?

☐ Can I reduce O(n²) to O(n)?

---

## Keywords

Prefix Sum

Running Sum

Cumulative Sum

Range Sum

Preprocessing

Subarray

Constant-Time Query

Optimization