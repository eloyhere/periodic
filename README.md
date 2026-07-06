# Cyclical Mathematics

> "The Tao gave birth to One, the One gave birth to Two, the Two gave birth to Three, and the Three gave birth to all myriad things." — *Tao Te Ching*
>
> "Mathematics is the language with which God has written the universe." — Galileo Galilei
>
> "Nothing is forever flat, nor does anything go without return." — *I Ching*
>
> "The universe is the sum total of information and its evolving relationships; mathematics is the proper subset through which humanity comprehends the universe." — Cyclical Mathematics

---

## Preface

Human understanding of the world begins with distinction—the carving of chaotic experience into recognisable units. A single leaf, a heartbeat, a sunrise. This primal discretisation marks the inception of all cognition and mathematics.

The *Tao Te Ching* states that "the Tao gave birth to One...", revealing the generative process from an indivisible whole to discrete units. The *I Ching* observes that "nothing is forever flat...", pointing to a fundamental characteristic of cosmic motion: all change unfolds through cycles and returns. Yet these ancient insights have long remained metaphorical, lacking formal expression.

The objective of Cyclical Mathematics is to reformulate these intuitions regarding discrete generation and cyclical evolution using rigorous mathematical language. It eschews specific cultural symbols or traditional terminology, proceeding instead from three foundational principles:

1.  **The universe is the sum total of information and its evolving relationships** — the information field, rather than matter or energy, constitutes the fundamental reality.
2.  **Mathematics is the proper subset through which humanity comprehends the universe** — mathematics formally captures the computable aspects of informational relationships.
3.  **Cyclicity is a universal feature of information evolution** — under the influence of gradient, divergence, and curl, the information field necessarily gives rise to discrete cyclical structures.

This document outlines the foundational framework of Cyclical Mathematics. We commence with the construction of numbers, proceed through vector and function theory, and culminate in field theory and its fundamental operators. No metaphysical or traditional cultural terms are employed; the exposition relies solely on the common language of mathematics and physics.

---

## Methodology

The construction of Cyclical Mathematics adheres to four cardinal rules:

1.  **Cognitive-Genetic Priority**
    The definitional order of mathematical objects must align with the logic of cognition: commencing from the simplest discrete distinctions and constructing increasingly complex relationships layer by layer. No concept is presupposed before its construction.
2.  **Non-Circular Construction**
    Each step utilises only rigorously defined objects. Real numbers and calculus may not be used to define natural numbers or integers; the concept of completeness may not precede the rational numbers.
3.  **Discrete Origin**
    The cognisable world originates in discrete distinction — the minimal unit of information. Continuity is a product of construction, not a presupposed substrate.
4.  **Symmetry as Directionality**
    Each new class of number introduces a novel symmetry operation: integers introduce additive inverses (0-symmetry); rationals introduce multiplicative inverses (1-symmetry); complexes introduce phase rotation (unit circle symmetry); quaternions introduce three-dimensional non-commutative rotation. These symmetries bestow "direction" upon numbers, enabling them to express orientation within specific relationships, beyond mere magnitude.

Guided by this methodology, we construct the standard number systems beginning with Peano's axioms, develop vector and function theory, and ultimately establish field theory.

---

## Number Systems

### Definition

Numbers are the symbolisation of stable structures within informational relationships. Number systems are algebraic structures extended hierarchically according to symmetry and completeness. Each stage introduces a new type of relationship, realised through strict equivalence class construction or completion.

### Natural Numbers $\mathbb{N}$

**Axioms (Peano Arithmetic)**

1.  $0$ is a natural number.
2.  Every natural number $n$ has a unique successor $S(n)$, which is also a natural number.
3.  $0$ is not the successor of any natural number.
4.  If $S(n) = S(m)$, then $n = m$.
5.  Axiom of Induction: If a property $P$ holds for $0$, and $P(n) \Rightarrow P(S(n))$ for all $n$, then $P$ holds for all natural numbers.

**Convention:** $1:=S(0),\;2:=S(1),\;\ldots$

**Operations (Recursive Definitions)**
-   Addition: $n+0:=n,\; n+S(m):=S(n+m)$
-   Multiplication: $n\times 0:=0,\; n\times S(m):=(n\times m)+n$
-   Order: $n\leq m\iff \exists k\in\mathbb{N},\; n+k=m$

$(\mathbb{N},+,\times,\leq)$ forms an ordered commutative semiring. Natural numbers possess only "magnitude," lacking inverses and symmetry. They are pure scalars, answering "how many discrete units."

### Integers $\mathbb{Z}$

**Construction** Define an equivalence relation $\sim$ on $\mathbb{N}\times\mathbb{N}$:
$(a,b)\sim(c,d) \iff a+d = b+c$

The set of integers $\mathbb{Z}:=(\mathbb{N}\times\mathbb{N})/\sim$. The equivalence class $[(a,b)]$ represents the displacement "from $b$ to $a$."

**Operations**
-   Addition: $[(a,b)]+[(c,d)]:=[(a+c,\;b+d)]$
-   Zero element: $0_{\mathbb{Z}}:=[(0,0)]$
-   Additive inverse: $-[(a,b)]:=[(b,a)]$
-   Multiplication: $[(a,b)]\times[(c,d)]:=[(ac+bd,\;ad+bc)]$
-   Unit element: $1_{\mathbb{Z}}:=[(1,0)]$
-   Order: $[(a,b)]\leq[(c,d)]\iff a+d\leq b+c$

$(\mathbb{Z},+,\times,\leq)$ forms an ordered commutative ring. Every element possesses an additive inverse, yielding 0-symmetry: for any integer $x$, there exists a unique $-x$ such that $x+(-x)=0$. This symmetry grants integers "directional displacement"—positive values indicate accumulation in one direction, negative values in the opposite. Integers may be viewed as vectors on a one-dimensional lattice (vectors in the $\mathbb{Z}$-module sense).

Natural embedding: $n\mapsto[(n,0)]$ preserves additive and multiplicative structure.

### Rational Numbers $\mathbb{Q}$

**Construction** Let $\mathbb{Z}^\times:=\mathbb{Z}\setminus\{0\}$. Define $\approx$ on $\mathbb{Z}\times\mathbb{Z}^\times$:
$(a,b)\approx(c,d) \iff a\times d = b\times c$

The set of rational numbers $\mathbb{Q}:=(\mathbb{Z}\times\mathbb{Z}^\times)/\approx$. Equivalence classes are denoted $\frac{a}{b}$.

**Operations**
-   Addition: $\frac{a}{b}+\frac{c}{d}:=\frac{a\times d+b\times c}{b\times d}$
-   Zero element: $\frac{0}{1}$; Additive inverse: $-\frac{a}{b}:=\frac{-a}{b}$
-   Multiplication: $\frac{a}{b}\times\frac{c}{d}:=\frac{a\times c}{b\times d}$
-   Unit element: $\frac{1}{1}$; Multiplicative inverse: if $a\neq 0$, $(\frac{a}{b})^{-1}:=\frac{b}{a}$
-   Order: $\frac{a}{b}>0\iff a\times b>0$, with total order derived accordingly.

$(\mathbb{Q},+,\times,\leq)$ forms an ordered field. Non-zero elements possess not only additive inverses (0-symmetry) but also multiplicative inverses (1-symmetry): for any $x\neq 0$, there exists $x^{-1}$ such that $x\times x^{-1}=1$. This symmetry grants rationals "scaling direction"—$x$ and $x^{-1}$ are symmetric about 1, representing magnification and reduction respectively. Natural embedding: $n\mapsto\frac{n}{1}$.

### Real Numbers $\mathbb{R}$

**Construction (Dedekind Cut)** The set $\mathbb{R}$ consists of all lower sets $L\subset\mathbb{Q}$ satisfying:
1.  $L\neq\emptyset$, $L\neq\mathbb{Q}$.
2.  $L$ has no greatest element.
3.  If $x\in L$, $y\in\mathbb{Q}$, and $y<x$, then $y\in L$ (downward closure).

A rational $q$ corresponds to the lower set $\{x\in\mathbb{Q}\mid x<q\}$.

**Operations**
-   Order: $r\leq s\iff L_r\subseteq L_s$
-   Addition: $L_{r+s}:=\{x+y\mid x\in L_r,\;y\in L_s\}$
-   Multiplication: Defined first for positive reals as $\{xy\mid x\in L_r,y\in L_s,x,y>0\}\cup\mathbb{Q}_{\leq 0}$, extended by sign.

$\mathbb{R}$ satisfies the least upper bound property (completeness). Reals retain additive and multiplicative inverses (0 and 1-symmetry) whilst introducing continuity. They are the natural language for continuous field potentials: intensity, density, and rates of change are ultimately expressed via real numbers. The reals themselves form a one-dimensional $\mathbb{R}$-vector space, where each element acts as its own "position vector."

### Complex Numbers $\mathbb{C}$

**Construction** $\mathbb{C}:=\mathbb{R}^2$. Addition is component-wise; multiplication is defined as:
$(a,b)\times(c,d):=(ac-bd,\;ad+bc)$

Let $a+bi:=(a,b)$, $i:=(0,1)$, thus $i^2=-1$.

**Algebraic Structure** $\mathbb{C}$ is a two-dimensional commutative $\mathbb{R}$-algebra and a field. Every non-zero complex has an inverse $(a+bi)^{-1}=\frac{a-bi}{a^2+b^2}$.

**Polar Form and Rotational Symmetry**
Any $z\in\mathbb{C}$ can be written as $z=re^{i\theta}$, where $r=|z|=\sqrt{a^2+b^2}$ is the modulus and $\theta$ the argument. Multiplication $z\mapsto e^{i\phi}z$ preserves modulus whilst increasing the argument by $\phi$, effecting a plane rotation. The unit complex group $\{e^{i\theta}\}$ is isomorphic to $U(1)$. Beyond additive and multiplicative symmetry, complexes introduce unit circle rotational symmetry: the imaginary unit $i$ acts as a $90^\circ$ rotation operator. This makes complexes the natural vehicle for planar curl effects.

### Quaternions $\mathbb{H}$

**Construction** $\mathbb{H}:=\mathbb{R}^4$, with elements $q=a+bi+cj+dk$. Addition is component-wise. Multiplication follows bilinear expansion from:
-   $i^2=j^2=k^2=ijk=-1$
-   $ij=k,\; ji=-k$; $jk=i,\; kj=-i$; $ki=j,\; ik=-j$

Multiplication is non-commutative but associative. $\mathbb{H}$ is a non-commutative $\mathbb{R}$-division algebra.

**Conjugate and Norm** $\bar{q}:=a-bi-cj-dk$, $|q|:=\sqrt{a^2+b^2+c^2+d^2}$. Inverse of a non-zero element: $q^{-1}=\bar{q}/|q|^2$.

**Rotational Symmetry** The unit quaternion group $S^3$ is isomorphic to $SU(2)$, implementing three-dimensional rotations via $v\mapsto qvq^{-1}$ ($v$ being a pure imaginary quaternion). The non-commutativity of different axis rotations corresponds to the non-commutativity of quaternion multiplication. Quaternions extend complex planar rotation to full three-dimensional non-commutative rotational symmetry, serving as the algebraic embodiment of spatial curl structure.

### Overview of Number Systems

| Number System | Symmetry | Type of Direction |
| :--- | :--- | :--- |
| $\mathbb{N}$ | None | Pure magnitude |
| $\mathbb{Z}$ | Additive (0-symmetry) | Displacement (positive/negative) |
| $\mathbb{Q}$ | Additive + Multiplicative (1-symmetry) | Scaling (magnify/reduce) |
| $\mathbb{R}$ | Above + Continuity & Completeness | Continuous intensity & limit direction |
| $\mathbb{C}$ | Above + Planar Rotational Symmetry $U(1)$ | Phase rotation direction |
| $\mathbb{H}$ | Above + 3D Rotational Symmetry $SU(2)$ | Spatial non-commutative rotation direction |

---

## Vectors

### Definition

A vector is an ordered tuple of numbers, used to represent quantities possessing both magnitude and direction. Depending on the underlying number system, vectors may be constructed over integers, rationals, reals, complexes, or quaternions. A vector space requires closure under addition and scalar multiplication, satisfying the relevant axioms.

-   $\mathbb{Z}^n$: Integer vectors, forming a lattice ($\mathbb{Z}$-module).
-   $\mathbb{Q}^n$: Rational vectors, forming a $\mathbb{Q}$-vector space.
-   $\mathbb{R}^n$: Real vectors, the standard Euclidean vector space.
-   $\mathbb{C}^n$: Complex vectors, basis of unitary spaces, carrying phase and rotation information.
-   $\mathbb{H}^n$: Quaternion vectors, describing 3D rotations and non-commutative transformations.

Fundamental operations include addition, scalar multiplication, inner products, and outer products (cross products). Vectors over different number systems possess distinct algebraic structures and geometric meanings. Any number system beyond the naturals exhibits some form of symmetry, allowing its elements to be treated as vectors: integers have displacement direction, rationals have scaling direction, complexes have phase direction, and quaternions have 3D rotation direction.

### Properties of Vector Types

| Vector Type | Component Field | Norm Definition | Direction Representation | Typical Operations | Physical Correspondence |
| :--- | :--- | :--- | :--- | :--- | :--- |
| Integer Vector | $\mathbb{Z}$ | Manhattan distance or lattice norm | Sign and ratio of components | Addition, subtraction, scalar mult. (integer) | Lattice displacement, discrete steps |
| Rational Vector | $\mathbb{Q}$ | Euclidean norm (sqrt may be irrational) | Ratio of components | Addition, scalar mult. (rational), dot product | Scaled positions |
| Real Vector | $\mathbb{R}$ | $\sqrt{\sum x_i^2}$ | Angle with coordinate axes | Addition, scalar mult., dot/cross product (3D) | Velocity, force, field strength |
| Complex Vector | $\mathbb{C}$ | $\sqrt{\sum \|z_i\|^2}$ | Argument and relative phase | Addition, scalar mult. (complex), inner product | EM wave amplitude/phase, quantum states |
| Quaternion Vector | $\mathbb{H}$ | $\sqrt{\sum \|q_i\|^2}$ | Rotation axis and angle | Addition, scalar mult. (quaternion), non-comm. mult. | 3D rotation, rigid body attitude |

### Vector Relations and Operations

The following defines fundamental relations and operations between vectors and scalars. All definitions are based on pure mathematical and physical meaning, without reference to specific symbolic systems.

| Concept | Mathematical Meaning | Physical Meaning | Property | Note |
| :--- | :--- | :--- | :--- | :--- |
| Addition | Component-wise sum | Force composition, displacement superposition | Commutative, associative | Parallelogram law |
| Subtraction | Component-wise difference | Relative displacement, force decomposition | Adding inverse $a - b = a + (-b)$ | |
| Scalar Multiplication | Multiply all components by a scalar | Scaling, intensity adjustment | Changes norm, preserves/reverses direction | Negative scalar reverses |
| Dot Product (Inner) | $\vec{a}\cdot\vec{b} = \sum a_i b_i$ | Work, projection, energy coupling | Commutative, yields scalar | Zero if orthogonal |
| Projection | $\text{proj}_{\vec{b}}\vec{a} = \frac{\vec{a}\cdot\vec{b}}{\vec{b}\cdot\vec{b}}\vec{b}$ | Component along a given direction | Collinear with $\vec{b}$ | Zero if orthogonal |
| Cross Product (1D) | $a\times b := 0$ | No rotational degree of freedom | Always zero | No curl in 1D |
| Cross Product (2D) | $z_1\times z_2 := \text{Im}(\bar{z}_1 z_2) = ad - bc$ | Signed area, 2D vorticity | Scalar, anti-commutative | Positive = CCW, negative = CW |
| Cross Product (3D) | $\vec{a}\times\vec{b}$, magnitude $\|\vec{a}\|\|\vec{b}\|\sin\theta$, direction by RHR | Torque, angular momentum, 3D vorticity | Anti-commutative, yields vector | Full 3D curl |
| Complex Multiplication | Moduli multiply, arguments add | Amplitude modulation & phase rotation | Planar rotation & scaling | $i$ rotates by $90^\circ$ |
| Quaternion Multiplication | Non-commutative, associative | Composition of 3D rotations | Order matters | Unit quats represent rotations |
| Division | Multiplication by inverse (where defined) | Attenuation, inverse filtering, inverse rotation | Requires existence of inverse | Complex: $z_1/z_2 = z_1\bar{z}_2/\|z_2\|^2$ |
| Real Part | Take real/scalar component, zero others | Extract linear component (gradient/divergence) | Project onto $\mathbb{R}$ axis | Zero for pure imaginaries |
| Imaginary Part | Take imaginary/vector component, zero real | Extract rotational component (curl) | Project onto pure imaginary space | Identity for pure imaginaries |
| Normalisation | Divide vector by its norm | Extract unit direction | Norm becomes 1 | Used for comparing directions |
| Parallel | Vectors are scalar multiples (real coeff.) | Motion in same/opposite direction | Angle $0^\circ$ or $180^\circ$ | Dot product = $\pm$ product of norms |
| Orthogonal | Dot product is zero | Independent components, orthogonal decomposition | Angle $90^\circ$ or $270^\circ$ | Requires at least 2D |
| Angle | Angular difference between vectors | Phase difference, directional deviation | $\cos\theta = \frac{\vec{a}\cdot\vec{b}}{\|\vec{a}\|\|\vec{b}\|}$ | Arg diff for complexes |
| Distance | Norm of difference vector | Spatial separation, potential difference | Satisfies triangle inequality | Euclidean or Manhattan |
| Common Origin | Vectors share starting point | Common reference frame, common source | Shared origin | Facilitates composition |
| Common Terminus | Vectors share end point | Energy convergence, common target | Shared terminus | Paths to a single point |
| Propagation | Time evolution of a vector field | Wave propagation, information transfer | Governed by grad, div, curl | First derivative = velocity |
| Reflection | Mirror of vector across normal | Elastic collision, interface reflection | Incidence angle = reflection angle | Preserves norm, changes direction |
| Refraction | Change of direction entering medium | Speed change, phase delay | Snell's Law | Ratio of norms relates to index |
| Normal (1D) | $\text{Normal}(a) := a i$ (lift to 2D) | Orthogonality requires higher dimension | Yields pure imaginary | No intrinsic orthogonality in 1D |
| Normal (2D) | $\text{Normal}(z) := z i$ (rotate $90^\circ$) | Orthogonal direction in plane | Remains in 2D | Multiplying by $i$ rotates $90^\circ$ |
| Normal (3D) | Via cross product, perpendicular to plane | Reflection/refraction interface | Direction by RHR | Not unique (sign ambiguity) |
| Polar Decomposition | Decompose complex/quat into norm and unit mod. | Separate intensity and rotation | $z = re^{i\theta}$ | Analyse strength vs. phase |

### Cross Product and Normal by Dimension

| Dimension | Number System | Symmetries Present | Cross Product | Normal |
| :--- | :--- | :--- | :--- | :--- |
| 1D | $\mathbb{Z}, \mathbb{Q}, \mathbb{R}$ | Additive (0), Multiplicative (1) | Always zero | Lift to 2D |
| 2D | $\mathbb{C}$ | Above + Planar Rotational $U(1)$ | Scalar | Within space |
| 3D | $\mathbb{H}$ (pure imag.) | Above + 3D Rotational $SU(2)$ | Vector | Given by cross product |

These operations constitute the basic language for analysing information flow in fields. In subsequent sections on fields, gradient, divergence, and curl will operate on vector fields, providing computational tools for local field behaviour.

---

## Functions

### Definition

Let $X,Y$ be constructed number systems or their Cartesian products. A function $f:X\to Y$ is a rule assigning a unique $y\in Y$ to each $x\in X$, denoted $f(x)=y$. Functions encapsulate dependencies between variables within the information field.

### Elementary Functions

Over the reals, elementary functions comprise six classes, generating all elementary functions via finite arithmetic operations and composition.

| Category | Expression | Domain | Range | Key Property |
| :--- | :--- | :--- | :--- | :--- |
| Constant | $f(x) = c$ | $\mathbb{R}$ | $\{c\}$ | Invariant |
| Power | $f(x) = x^a$ ($a\in\mathbb{R}$) | Depends on $a$ | Depends on $a$ | Repeated mult./div. for integer $a$ |
| Exponential | $f(x) = a^x$ ($a>0, a\neq 1$) | $\mathbb{R}$ | $\mathbb{R}^+$ | Rate of change proportional to self |
| Logarithm | $f(x) = \log_a x$ ($a>0, a\neq 1$) | $\mathbb{R}^+$ | $\mathbb{R}$ | Inverse of exponential |
| Trigonometric | $\sin x,\; \cos x,\; \tan x,\; \cot x,\; \sec x,\; \csc x$ | Depends | Periodic/Bounded/Discontinuous | Coordinates on unit circle |
| Inverse Trig. | $\arcsin x,\; \arccos x,\; \arctan x$, etc. | $[-1,1]$ or $\mathbb{R}$ | Bounded intervals | Inverses of trig. functions |

These six classes form the vocabulary for expressing growth, decay, oscillation, and other fundamental evolutionary laws. Exponential and trigonometric functions unify in the complex domain via Euler's formula $e^{i\theta}=\cos\theta + i\sin\theta$, central to cyclial complex analysis.

### Complex Functions

When domain and codomain extend to $\mathbb{C}$, we enter complex analysis. The core of Cyclical Mathematics is the complex exponential form:

$f(\tau) = A(\tau) \cdot e^{i(\omega\tau + \phi)}$

Here $\tau$ is a real variable (time or parameter), $A(\tau) \in \mathbb{C}$ is a time-varying complex amplitude, $\omega\in\mathbb{R}$ the angular frequency, and $\phi\in\mathbb{R}$ the initial phase. $|A(\tau)|$ represents instantaneous energy intensity; $\arg A(\tau)$ contributes additional phase modulation. For constant $A$, this describes uniform circular motion; for varying $A$, it describes complex periodic motion with evolving energy and phase.

Any sufficiently smooth periodic function can be expanded into a series of such functions (Fourier series), where $A(\tau)$ corresponds to the time-varying spectral envelope of that frequency component.

**Key Parameters of the Complex Exponential** (forming the basic vocabulary for discrete cycle sequences):

| Parameter | Symbol | Mathematical Definition | Physical Meaning | Description |
| :--- | :--- | :--- | :--- | :--- |
| Period Length | $p$ | Smallest $p>0$ s.t. $f(\tau+p)=f(\tau)$ | Span for one complete oscillation | Determines total elements in sequence |
| Sampling Rate | $r$ | Sampling step per period | Angular resolution, precision | $r=2\pi/p$ (Nyquist) |
| Samples per Cycle | $n$ | $n = p/r$ | Number of discrete states | Length of cycle sequence |
| Frequency | $f$ | $f = 1/p$ | Cycles per unit parameter | Dimensionless or temporal |
| Complex Amplitude | $A(\tau)$ | $A(\tau) \in \mathbb{C}$ | Dynamic energy & phase evolution | Modulus = energy, arg = phase shift |
| Angular Frequency | $\omega$ | $\omega = 2\pi f = 2\pi/p$ | Rate of phase change | Radians per unit |
| Phase | $\phi$ | Initial offset, $f(0)=A(0)e^{i\phi}$ | Initial condition | Starting position in cycle |

### Decibels and Energy Measurement

In Cyclical Mathematics, energy is proportional to the square of amplitude: $E(\tau) \propto |A(\tau)|^2$. To compare energy levels, decibels (dB) provide a logarithmic scale:

$\text{dB}(\tau) = 20 \log_{10}\left(\frac{|A(\tau)|}{A_0}\right),$

where $A_0$ is a reference amplitude. Positive dB indicates energy above reference, negative below. Decibels offer a compact representation of energy distribution in spectral analysis.

### Higher-Dimensional Functions

Extending domains to $\mathbb{R}^n$ or $\mathbb{C}^n$ yields multivariate functions. For vector-valued functions $\mathbf{F}:\mathbb{R}^n\to\mathbb{R}^n$, divergence and curl are defined (see Fields). Quaternion functions $f:\mathbb{H}\to\mathbb{H}$ encode 3D rotational fields and curl evolution.

### Limits

**Definition** Let $f$ be defined in a deleted neighbourhood of $a$. If there exists $L$ such that for every $\varepsilon>0$, there exists $\delta>0$ where $0<|x-a|<\delta$ implies $|f(x)-L|<\varepsilon$, then $L$ is the limit of $f(x)$ as $x$ approaches $a$, written:

$\lim_{x\to a} f(x) = L.$

One-sided, infinite, and limits at infinity are defined analogously.

**Properties:**
-   Uniqueness (if it exists).
-   Preservation under arithmetic (provided denominators are non-zero).
-   Squeeze Theorem: If $g(x)\leq f(x)\leq h(x)$ and $\lim g = \lim h = L$, then $\lim f = L$.

Limits underpin continuity, derivatives, integrals, and series. They formalise "infinite approximation," precisely describing instantaneous change, local tendencies, and cumulative processes in fields.

### Derivatives

For a real function $f:\mathbb{R}\to\mathbb{R}$, the derivative is:

$f'(x) := \lim_{h\to 0}\frac{f(x+h)-f(x)}{h}$

if the limit exists. It measures the instantaneous rate of change. For complex functions, differentiation is defined via real/imaginary parts or Cauchy-Riemann conditions.

Higher-order derivatives $f^{(n)}$ reveal deeper structural behaviour. For $f(\tau)=A(\tau)e^{i(\omega\tau+\phi)}$, differentiation involves both $A(\tau)$ variation and rotation: $f'(\tau) = (A'(\tau) + i\omega A(\tau)) e^{i(\omega\tau+\phi)}$. If the fundamental step is a phase rotation $\Delta\theta$, state progression is described by this derivative operation.

| Concept | Mathematical Meaning | Physical Meaning | Description |
| :--- | :--- | :--- | :--- |
| First Derivative | $f'(\tau)$, instantaneous rate | Velocity field, local propagation | Direction to next state |
| Second Derivative | $f''(\tau)$, rate of change of rate | Acceleration field, trend change | Accelerating vs. decelerating |
| Third Derivative | $f'''(\tau)$, rate of acceleration | Jerk | Long-term curvature change |
| Nth Derivative | $f^{(n)}(\tau)$, higher-order diff. | Higher dynamics, long-range corr. | Tracking distant phase offsets |

### Integrals

The definite integral $\int_a^b f(x)\,dx$ is the limit of Riemann sums, representing cumulative effect over $[a,b]$. Integration is the inverse of differentiation (Fundamental Theorem of Calculus). In fields, integrals compute total information flow or phase accumulation along paths. Complex and path integrals capture circulation—the global manifestation of curl.

### Series Expansions and Integral Transforms

Analysing periodic phenomena relies heavily on decomposing functions into simple components. These tools form the spectral analysis library of Cyclical Mathematics.

#### Taylor Expansion

**Definition** If $f$ is infinitely differentiable at $a$:
$f(x) = \sum_{n=0}^{\infty} \frac{f^{(n)}(a)}{n!} (x-a)^n.$
At $a=0$, it is the Maclaurin series. Taylor expansions approximate smooth functions using polynomials, with coefficients from derivatives.

**Physical Meaning:** Decomposes local change into constant, linear (gradient), quadratic (curvature), etc., forming the basis for linearisation, stability analysis, and nonlinear corrections.

#### Fourier Series

**Definition** For a sufficiently smooth periodic function $f(t)$ with period $T$:
$f(t) = \frac{a_0}{2} + \sum_{n=1}^{\infty} \left( a_n \cos\frac{2\pi n t}{T} + b_n \sin\frac{2\pi n t}{T} \right) = \sum_{n=-\infty}^{\infty} c_n e^{i\frac{2\pi n}{T}t}.$
Coefficients $c_n$ are the spectrum, encoding amplitude and phase of frequency components.

**Physical Meaning:** Any periodic motion is a superposition of simple harmonics. Spectral analysis transforms complex waveforms into clear frequency-domain energy distributions, identifying dominant periods and harmonic structures.

#### Basis Transformations (Radix-n FFT)

Fast Fourier Transforms (FFT) use different bases for different sequence lengths.

| Concept | Mathematical Meaning | Physical Meaning | Description |
| :--- | :--- | :--- | :--- |
| Radix-2 FFT | Length $N=2^k$, dyadic decomposition | Efficient binary spectrum calc. | Most common, power-of-two required |
| Radix-3 FFT | Length $N=3^k$, triadic recursion | Analysis of ternary structures | Suited for three-body coupling |
| Radix-5 FFT | Length $N=5^k$, pentadic decomp. | Analysis of five-fold symmetry | Suited for quintic cycles |
| Radix-7 FFT | Length $N=7^k$, heptadic decomp. | Analysis of seven-fold periodicity | Suited for weekly cycles, heptatonic scales |

#### Integral Transform Toolbox

Transforms mapping time-domain to frequency-domain (or complex frequency-domain).

| Transform | Mathematical Meaning | Physical Meaning | Description |
| :--- | :--- | :--- | :--- |
| DFT | Discrete spectrum of finite sequence | Harmonic decomposition of digital sig. | Foundation, FFT is fast algorithm |
| IDFT | Reconstruct sequence from spectrum | Signal synthesis | Inverse of DFT |
| DTFT | Continuous spectrum of infinite sequence | Frequency response of digital filters | Spectrum is periodic & continuous |
| CTFT | Continuous spectrum of continuous signal | Ideal spectrum of analogue signals | Theoretical model |
| FFT | Efficient DFT via base-n decomposition | Real-time spectral analysis | Complexity $O(N\log N)$ |
| STFT | Segmented DFT with sliding window | Time-frequency analysis of non-stationarity | Reveals freq. variation over time |
| Wavelet | Inner product with scalable, translatable basis | Multi-resolution time-frequency localisation | Superior to STFT for transients |
| CZT | Z-transform along spiral contour | Arbitrary path spectrum, chirp analysis | Flexible freq. band/resolution |
| Bluestein | Compute DFT of arbitrary length via convolution | Optimisation for non-power-of-two | Converts DFT to convolution |
| Laplace | Complex exponential weighted integral | Analysis of growth/decay & transients | Converts ODEs to algebraic eqns |

### Diffusion Kernels

Diffusion kernels (convolution kernels) smooth, filter, or simulate information propagation. They correspond to different diffusion modes in field theory.

| Kernel Function | Mathematical Form | Physical Meaning | Description |
| :--- | :--- | :--- | :--- |
| Gaussian | $e^{-x^2/2\sigma^2}$ | Normal diffusion, heat conduction | Smooth, no ringing |
| Exponential | $e^{-\lambda \|x\|}$ | Radioactive decay, unilateral diffusion | Rapid decay, Laplace distribution |
| Inverse Distance | $1/\|x\|$ | Gravity, electrostatic potential | Long-range, weak, singular at origin |
| Cauchy | $1/(1+x^2)$ | Lorentzian lineshape, heavy tails | Robust to outliers, long-range |
| Triangular | Piecewise linear: $1-\|x\|$ (for $\|x\|<1$) | Linear interpolation, local averaging | Simple, compact support |
| Sinc | $\sin(x)/x$ | Ideal low-pass filtering | Rectangular freq. window, perfect HF removal |
| Bessel | $J_0(x)$ | Cylindrical waves, radial symmetry | Natural solution for circular symmetry |
| Laplacian | $e^{-\sqrt{x^2}}$ | Sharp edges, edge detection | First-order edge detection |

### Spectral Dynamics

With spectral representations, field behaviour can be controlled and predicted via spectral manipulation. Spectral dynamics studies the interaction, propagation, and evolution of frequency components within the information field.

**Spectral Operations:**

| Concept | Mathematical Meaning | Physical Meaning | Description |
| :--- | :--- | :--- | :--- |
| Spectral Convolution | Product of two signals in freq. domain | Filter response, combined effect | Time conv. = freq. mult. |
| Spectral Projection | Inner product with a basis function | Energy allocation to direction/freq. | Extract specific component |
| Point Perturbation | Modulate magnitude/phase of single freq. | Resonant excitation, local impulse | Single-frequency driving |
| Band Perturbation | Modulate a frequency band | Bandwidth excitation, global impulse | Affects contiguous frequencies |
| Point Diffusion | Smooth a spectral point via kernel | Information dispersion, thermal diff. | Energy spreads to neighbours |
| Band Diffusion | Wave equation evolution on spectrum | Wave propagation, periodic diffusion | Wave transport in freq. space |

**Spectral Applications:**

| Concept | Mathematical Meaning | Physical Meaning | Description |
| :--- | :--- | :--- | :--- |
| Spectral Analysis | Fourier decomposition of field | Signal decomposition, identify periods | Find dominant frequencies |
| Spectral Interference | Coherent superposition of components | Enhancement/cancellation, fringes | Constructive/destructive interference |
| Spectral Computation | Predict response via freq.-domain ops | System output for input spectrum | Quantitative evolution assessment |
| Spectral Interference (Noise) | Introduce noise/unrelated frequencies | Signal corruption, negative effect | Degrades original structure |
| Spectral Filtering | Retain/amplify bands, attenuate others | Signal purification, select favourable | Band-pass, notch, etc. |
| Spectral Coupling | Locking/synchronisation between freqs. | Resonance enhancement, combination | Frequency locking, energy transfer |
| Spectral Suppression | Targeted attenuation of frequencies | Weaken adverse factors | Notch filtering |
| Spectral Convolution (Global) | Convolve spectrum with multiple kernels | Feature extraction, comprehensive eval. | Multi-dimensional analysis |

---

## Elements of Cyclical Analysis

Before entering continuous field dynamics, we establish concepts for describing cyclical phenomena. These elements unify continuous evolution, discrete sampling, frequency-domain representation, and physical measurement. They bridge function theory and field theory—each field state captured via sampling and spectral analysis forms a discrete cycle sequence element.

| Concept | Mathematical Meaning | Physical Meaning | Description |
| :--- | :--- | :--- | :--- |
| Time | Evolution parameter, usually $t\in\mathbb{R}$ | Direction of causal sequence | 1D continuum marking field frames |
| Period | Smallest $T>0$ s.t. $f(t+T)=f(t)$ | Duration for one complete cycle | Determined by boundary conditions |
| Frequency | $f=1/T$ | Cycles per unit time | Related to angular freq. $\omega=2\pi f$ |
| Resolution | Time step $\Delta t$ or freq. interval $\Delta f$ | Precision and discrimination | Denser sampling resolves more freqs. |
| Trend | Low-freq. envelope or gradient direction | Macroscopic direction of evolution | Long-term trajectory after removing HF |
| Phasor | Complex amplitude $Ae^{i\phi}$ (ignoring $e^{i\omega t}$) | Steady-state amp. & phase | Converts ODEs to algebraic eqns. |
| Waveform | Specific shape of $f(t)$ | Instantaneous value trajectory | Sinusoidal, square, sawtooth, etc. |
| Spectrum | Fourier coefficients $c_n$ or transform $\hat{f}(\omega)$ | Energy & phase distribution per freq. | Reveals harmonic structure |
| Sample | Field value $f(t_k)$ at discrete time $t_k$ | Snapshot of continuous field | Single measurement or record |
| Sampler | Sampling function or sequence $\{t_k\}$ | Rule determining when/how to measure | Must satisfy Nyquist criterion |

These elements unify continuous descriptions (time, waveform, spectrum) with discretisation (sampling, resolution). From the fundamental field perspective, each sample is a snapshot at a specific phase; the totality of samples constitutes a discrete cycle sequence—the core object classified and predicted by Cyclical Mathematics.

---

## Fields

Differential and integral calculus on vector functions provides the language for describing local behaviour in continuous media. In Cyclical Mathematics, these operators centre on a fundamental field whose dynamics uniformly encompass gradient, divergence, and curl.

### Definition

Cyclical Mathematics postulates a fundamental field whose dynamics are described by equations incorporating gradient, divergence, and curl. Under these dynamics, the field spontaneously generates stable, isolated local structures. The complete classification of these structures corresponds precisely to the established number systems ($\mathbb{N}$ to $\mathbb{H}$) and their algebraic symmetries.

Mathematically, this fundamental field is projected into two basic forms:

-   **Scalar Field** $\phi: \mathcal{M}\to \mathbb{R}$: Assigns an information density or potential value to each point.
-   **Vector Field** $\mathbf{F}: \mathcal{M}\to T\mathcal{M}$: Assigns a magnitude and direction of information flow to each point.

The evolution of the field is the central subject of Cyclical Mathematics. Local behaviour is entirely characterised by three operators: gradient, divergence, and curl. They control directional differences in density, source/sink strength of flow, and closed loops of flow, respectively.

### Gradient

**Definition** For a scalar field $\phi$, its gradient $\nabla\phi$ is a vector field pointing in the direction of steepest increase, with magnitude equal to the directional derivative in that direction:

$\nabla\phi = \left( \frac{\partial\phi}{\partial x_1}, \frac{\partial\phi}{\partial x_2}, \dots, \frac{\partial\phi}{\partial x_n} \right)$

**Significance** The gradient reveals spatial asymmetry in information density. The field tends to flow from low to high density (or vice versa). The gradient direction defines local "increase," constituting the field-theoretic root of additive symmetry (positive/negative direction). When the field forms periodic potential wells under the gradient, discrete stable states emerge—the dynamic origin of integer "sequence direction."

### Divergence

**Definition** For a vector field $\mathbf{F}=(F_1,\dots,F_n)$, its divergence is a scalar field:

$\nabla\cdot\mathbf{F} = \frac{\partial F_1}{\partial x_1} + \frac{\partial F_2}{\partial x_2} + \cdots + \frac{\partial F_n}{\partial x_n}$

**Significance** Divergence measures the "source" or "sink" strength of information flow at a point. Positive divergence indicates generation (outflow); negative divergence indicates annihilation (inflow). Comparing divergences yields scaling relationships—the ratio of strengths defines magnification or reduction, the field-theoretic root of rational multiplicative symmetry (1-symmetry). Periodic source-sink structures yield quantifiable proportions.

### Curl

**Definition** For a 3D vector field $\mathbf{F}$, curl is a vector field:

$\nabla\times\mathbf{F} = \left( \frac{\partial F_3}{\partial x_2} - \frac{\partial F_2}{\partial x_3},\; \frac{\partial F_1}{\partial x_3} - \frac{\partial F_3}{\partial x_1},\; \frac{\partial F_2}{\partial x_1} - \frac{\partial F_1}{\partial x_2} \right)$

In 2D, curl reduces to the scalar $\frac{\partial F_2}{\partial x_1} - \frac{\partial F_1}{\partial x_2}$.

**Significance** Curl measures the local rotational intensity of flow. Where curl is non-zero, flow does not proceed linearly but forms closed vortices around a local axis. Curl is the field-theoretic root of rotational symmetry (unit circle and 3D rotation): 2D curl induces planar rotation (complex phase); 3D curl components correspond to the imaginary parts of quaternions (non-commutative algebra). Stable curl structures yield closed cycles—circular motion, vortices, cyclic sequences.

### Synergy of Operators and Emergence of Cycles

Gradient, divergence, and curl do not act independently. Field evolution typically includes all three. A simplified model:

$\frac{\partial\mathbf{F}}{\partial t} = \alpha\nabla\phi + \beta\nabla\cdot\mathbf{F} + \gamma\nabla\times\mathbf{F}$

with coupling constants $\alpha,\beta,\gamma$. Such dynamics naturally generate discrete stable structures: periodic potential wells (natural number nodes), directed flow (integer displacement), convergence/divergence ratios (rational scaling), continuous intensity (real potential), closed vortices (complex phase), and 3D rotational vortex tubes (quaternion direction).

Sampling and combining these structures yields discrete cycle sequences with fixed phase differences. Each element is a snapshot at a specific phase; adjacent elements are linked by fixed operator actions—gradient advance, divergence scaling, or curl phase rotation. The entire sequence forms a complete cycle, its length and structure determined by eigenfrequencies and boundary conditions.

Thus, the dynamics of the fundamental field generate all number systems and symmetries, organising them into observable cycle sequences. Cyclical Mathematics employs all preceding tools—from naturals to quaternions, vectors to complex functions, limits to gradients—to classify and predict these sequences. Without metaphor or cultural symbolism, purely through field operator dynamics, it recapitulates the logic of "the Tao gave birth to One...": from structureless substrate to discrete counting, to directed sequences, to proportion, continuity, rotation, culminating in the complex symphony of all things.

---

## Waves and Fields: Dynamics and Geometry

Having constructed number systems, vectors, functions, and fields, we now discuss the dynamic relationship between waves and fields, and their unified geometric representation.

### Geometric Essence of Waveforms and Spectra

A waveform is a continuous complex function $f(\tau)$ or the integral reconstruction of discrete samples. Its values can be any directed number—real, complex, or quaternion—supporting rotation (phase advance) and scaling (amplitude change). The waveform is the direct temporal presentation of information.

A spectrum is the discrete set of points in the frequency domain resulting from the Fourier transform of the waveform. Resolution in the frequency domain is determined by the sampling rate. Each spectral point is a directed number, carrying amplitude (modulus) and phase (argument) for that frequency component. The spectrum is the hidden cyclical structure behind the waveform.

### Generation of Fields: The Magnetisation Process

Field generation is a "magnetisation" process—in a disordered state, information flow directions are random and cancel out macroscopically. When external conditions or internal coupling induce local ordering, divergence (sources/sinks), gradient (potential differences), and curl (vortices) emerge, giving birth to the field. The field maintains static spatiotemporal relations—where potential wells lie, where sources are, and around which axes vortices rotate.

### Hierarchy: Fields, Waves, Spectra

The field is the most fundamental structure, defining operator states (gradient, divergence, curl distribution) at every point. When fields interfere or couple, static equilibrium breaks, and perturbations propagate as waves. During propagation, waves interact continuously with local gradient, divergence, and curl—gradient accelerates/decelerates, divergence converges/diverges energy, curl imparts polarisation.

The wave's temporal form (waveform) yields a spectrum via sampling and Fourier transformation. The spectrum reveals all cyclical components within the wave—dominant frequencies, suppressed ones, and phase relationships.

The relationship is summarised as:

```
Field → interference/coupling → Wave → sampling+transform → Spectrum
```

The reverse holds: spectra synthesise waves; wave energy distributions can alter field sources and vortices.

### Layered Operations

Different operations apply to different layers:

**Point Operations (Local):**
-   **Point Interference:** Impulse excitation at a single point in field/wave/spectrum.
-   **Point Diffusion:** Smooth energy to neighbours via kernel (time or frequency smoothing).

**Wave Operations (Time Domain):**
-   **Wave Interference:** Coherent superposition of waves, producing fringes.
-   **Wave Coupling:** Energy exchange between frequencies/directions (frequency locking, mode conversion).

**Field Operations (Spatial):**
-   **Field Interference:** Overlap of gradient/divergence/curl distributions altering sources/vortices.
-   **Field Coupling:** Nonlinear terms causing energy transfer between field components.

**Spectral Operations (Frequency Domain):**
-   **Spectral Interference:** Coherent superposition of frequency components.
-   **Spectral Coupling:** Phase locking between frequencies, forming harmonics or combs.

### Unified Geometric Picture

All operations acquire geometric representation in phase space. The waveform is a trajectory (parametric curve); the field is a vector field (arrows at points); the spectrum is a set of points on the complex plane (one per frequency).

-   **Rotation** corresponds to phase advance—rotation about origin or unit sphere in complex/quaternion space.
-   **Scaling** corresponds to amplitude change—radial scaling, logarithmic energy change.
-   **Diffusion** corresponds to smoothing of point sets—energy "leaking" to neighbours.
-   **Interference** corresponds to vector addition/subtraction—synthesis or cancellation.
-   **Coupling** corresponds to nonlinear transformation—multiplication creating sum/difference frequencies (new spectral points).

### Wave Nature of Objects and Energy

In Cyclical Mathematics, objects and energy propagate as waves. A "particle" is merely a wave packet—a spatially localised waveform carrying curl (spin), gradient (momentum), and divergence (mass/energy source). Wave packets constantly interact with spatial gradient (potential), divergence (source/sink), and curl (vortex) fields during propagation. This unifies classical and quantum forces: gravity corresponds to divergence (mass convergence); electromagnetism to curl (charge rotation); strong/weak interactions to gradient (nuclear potential wells).

This perspective weaves field operators (gradient, divergence, curl), wave behaviour (propagation, interference, coupling), and spectral structure (harmonics, noise, resonances) into a coherent whole—all phenomena in the universe are the geometric dance of waves and operators in the information field.

---

<div align="center">

**Cyclical Mathematics**
<br>
© 2026 Fu Zi
<br>
License: MIT (Because the universe is open source)

</div>
