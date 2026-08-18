# FAANG - Trapping rainwater

README — Trapping Rainwater (brief)

Problem
- Given an array of non-negative integers representing elevation heights, compute how much water is trapped after raining.

Bug found
- The original code indexed height[r] when r could equal height.size(), causing an out-of-range access and a debug breakpoint in std::vector::operator[].

Fix applied
- Stop the right-side scan before the vector end:

```cpp
while (r < height.size()) {
    maxR = max(maxR, height[r]);
    r++;
}