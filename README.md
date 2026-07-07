# Periodic Mathematics

> “The Tao gave birth to One; One gave birth to Two; Two gave birth to Three; Three gave birth to all myriad things.” — *Tao Te Ching*
> “Mathematics is the language with which God has written the universe.” — Galileo Galilei
> “No plain always slopes, nor guidance always returns.” — *I Ching*

---

## Foundational Postulates

The following postulates do not constitute mathematical derivations but serve as philosophical starting points and research motivations for Periodic Mathematics.

**Postulate 1 (Ontology of Information)**
The fundamental constituents of the universe are information and its relations; matter and energy are derivative phenomena arising from relational structures of information.

**Postulate 2 (Mathematics as a Proper Subset)**
Mathematics represents that subset of the universe’s informational relations which is formalisable and computable. Not all informational relations have been mathematised.

**Postulate 3 (Universality of Periodicity)**
Periodicity is a universal characteristic of information evolution. Under appropriate conditions, stable periodic structures emerge naturally from informational relations.

> The mathematical treatment commences in the subsequent section; henceforth, the aforementioned philosophical postulates shall not be invoked.

---

## Methodology

Periodic Mathematics adopts all standard constructions of modern mathematics without redefining extant concepts. Its programme is as follows:

1.  To elucidate **symmetry and directionality** as the foundations of periodicity;
2.  To furnish a rigorous definition of periodicity within the language of group theory, proceeding from symmetry;
3.  To reveal the structural correspondence between number system extensions and the accretion of symmetry groups;
4.  To establish corresponding periodic functions for each number system;
5.  To subsume Fourier analysis and other integral transforms within a harmonic analysis framework on periodic groups;
6.  To provide a categorical description unifying the computation of waves and spectra.

---

## Part I: Symmetry and Directionality—The Basis of Periodicity

The root of periodicity lies in symmetry. A system exhibits periodic behaviour when a transformation exists under which the system remains invariant. The collection of such transformations constitutes a group, whilst the directionality of the group action imparts a "sense" to the period. This chapter expounds how symmetry engenders directionality, and how directionality serves as the mathematical foundation of periodicity.

### 1.1 Symmetry

**Definition 1 (Symmetry)**
Let $S$ be a set. A symmetry on $S$ is an invertible transformation $\sigma: S \to S$ that preserves a specified structure. The set of all symmetries on $S$, under composition, forms a group termed the **symmetry group** (or automorphism group) of $S$.

**Example 1 (Geometric Symmetry)**
*   The symmetry group of the unit circle $S^1$ is the orthogonal group $O(2)$ (all rotations and reflections).
*   The symmetry group of a regular $n$-gon is the dihedral group $D_n$.
*   The symmetry group of the full space $\mathbb{R}^n$ under translation is the additive group $\mathbb{R}^n$.

**Example 2 (Algebraic Symmetry)**
*   The integer additive group $(\mathbb{Z},+)$ admits the symmetry $x \mapsto -x$. This symmetry generates the group $C_2$ (the cyclic group of order two).
*   The multiplicative group of non-zero rationals $(\mathbb{Q}^\times,\times)$ admits the symmetry $x \mapsto x^{-1}$.
*   The complex field $\mathbb{C}$ admits rotational symmetry $z \mapsto e^{i\theta}z$, constituting the group $U(1)$.

### 1.2 Directionality

**Definition 2 (Directionality)**
Let $G$ be a Lie group acting on a smooth manifold $M$, with $\mathfrak{g}$ its Lie algebra. For a generator $X \in \mathfrak{g}$, the vector field $X_M(p)$ induced at $p \in M$ gives the infinitesimal direction of the $G$-action at $p$. If $G$ is discrete, direction is given by the progression of the generator within the state space. Multiple generators entail multiple independent directional dimensions.

Direction does not exist independently of symmetry; it is the product of the group action. Distinct generators of the same group may yield distinct directions.

### 1.3 Three Fundamental Symmetries and Directions

In the extension of number systems, three fundamental symmetric operations recur, each corresponding to a basic type of direction.

**(1) Additive Symmetry: 0-Symmetry and Displacement Direction**
Within the integers $\mathbb{Z}$, the symmetric operation $x \mapsto -x$ fixes $0$. This symmetry partitions the integers into positive and negative semi-axes. Positive numbers denote accumulation along one direction; negatives denote accumulation along the opposite. The resulting direction is termed the **displacement direction**.
*   **Property**: Additive symmetry is an involution—applying it twice yields the identity: $-(-x) = x$. It generates the group $C_2$.

**(2) Multiplicative Symmetry: 1-Symmetry and Scaling Direction**
Within the non-zero rationals $\mathbb{Q}^\times$, the symmetric operation $x \mapsto x^{-1}$ fixes $1$. This symmetry partitions the positive rationals into regions of magnification ($x > 1$) and diminution ($0 < x < 1$). The resulting direction is termed the **scaling direction**.
*   **Property**: Multiplicative symmetry is also an involution: $(x^{-1})^{-1} = x$. However, scaling direction is continuous—there exist degrees of magnification and diminution, not merely discrete directions.

**(3) Rotational Symmetry: $i$-Symmetry and Phase Direction**
Within the complex plane $\mathbb{C}$, the symmetric operation $z \mapsto iz$ (multiplication by the imaginary unit $i$) rotates by $90^\circ$. Powers of $i$ generate the discrete rotation group $\{1, i, -1, -i\}$, corresponding to four cardinal directions. Continuous rotation constitutes the group $U(1)$ via $z \mapsto e^{i\theta}z$. The resulting direction is termed the **phase direction** or **rotational direction**.
*   **Property**: Rotational symmetry is not an involution ($i^2 = -1 \neq 1$); four applications are required to return to unity ($i^4 = 1$). In three dimensions, the non-commutativity of rotation is described by $SU(2)$ (the group of unit quaternions).

### 1.4 From Symmetry to Periodicity

Symmetry is conceptually prior to periodicity. Periodicity is the structure manifested by the repeated application of a symmetry in a specific direction.

**Proposition 1 (Symmetry Generates Closed Periods and Orbits)**
Let $G$ be a symmetry group, and $H = \langle g \rangle \subset G$ the cyclic subgroup generated by a symmetric operation $g \in G$.
*   If $g$ has finite order (i.e., $\exists n \in \mathbb{N}^+$ s.t. $g^n = e$), the iteration of $g$ forms a closed period of length $n$.
*   If $g$ has infinite order (i.e., $g^k \neq e \; \forall k \neq 0$), the iteration forms an infinite orbit, never returning to the origin.

**Proof**: If $g^n = e$, the sequence $s, g\cdot s, g^2\cdot s, \dots$ returns to $s$ after $n$ steps, forming a cycle of length $n$. If $g$ has infinite order, the sequence contains no repetitions, forming an infinite orbit. $\square$

**Corollary 1**: The three fundamental symmetries correspond to three basic types of periods or orbits:
*   Additive Symmetry ($C_2$) → Two-state period (alternation of positive/negative)
*   Multiplicative Symmetry (Involution $x \mapsto x^{-1}$) → Geometric orbit (alternation of magnification/diminution)
*   Rotational Symmetry ($U(1)$) → Circular period (phase cycle)

### 1.5 Centres of Symmetry: 0, 1, $i$

Within the three fundamental symmetries, three special numbers act as the "centres" or "generators".
*   **0** is the fixed point of additive symmetry $x \mapsto -x$. It demarcates positive from negative and serves as the datum for displacement.
*   **1** is the fixed point of multiplicative symmetry $x \mapsto x^{-1}$. It demarcates magnification from diminution and serves as the datum for scaling.
*   **$i$** is the generator of the rotation group $U(1)$. Multiplication by $i$ corresponds to a $90^\circ$ rotation. Its powers generate the entire discrete rotation group.

> These three numbers will be linked interpretively to gradient, divergence, and curl in field theory (see Part VII). This linkage is theoretical interpretation, not an established mathematical theorem.

---

## Part II: Number Systems

Numbers are symbolisations of stable structures within informational relations. Number systems are algebraic structures extended hierarchically according to symmetry and completeness. Each extension introduces new symmetries, thereby introducing new directionalities.

### 2.1 Natural Numbers $\mathbb{N}$

**Axioms (Peano Arithmetic)**
1.  $0$ is a natural number.
2.  Every natural number $n$ has a unique successor $S(n)$, which is also a natural number.
3.  $0$ is not the successor of any natural number.
4.  $S(n) = S(m) \implies n = m$.
5.  Induction Axiom: If a property $P$ holds for $0$, and $P(n) \implies P(S(n))$ for all $n$, then $P$ holds for all natural numbers.

**Convention**: $1:=S(0),\;2:=S(1),\;\ldots$

**Operations (Recursive Definitions)**
*   Addition: $n+0:=n,\; n+S(m):=S(n+m)$
*   Multiplication: $n\times 0:=0,\; n\times S(m):=(n\times m)+n$
*   Order: $n\leq m\iff \exists k\in\mathbb{N},\; n+k=m$

$(\mathbb{N},+,\times,\leq)$ forms an ordered commutative semiring. Naturals possess only "magnitude", lacking inverses and symmetry. They are pure scalars answering "how many discrete units".

### 2.2 Integers $\mathbb{Z}$

**Construction** Define equivalence $\sim$ on $\mathbb{N}\times\mathbb{N}$:
$(a,b)\sim(c,d) \iff a+d = b+c$

The integers $\mathbb{Z}:=(\mathbb{N}\times\mathbb{N})/\sim$. The equivalence class $[(a,b)]$ represents the displacement "from $b$ to $a$".

**Operations**
*   Addition: $[(a,b)]+[(c,d)]:=[(a+c,\;b+d)]$
*   Zero: $0_{\mathbb{Z}}:=[(0,0)]$
*   Additive Inverse: $-[(a,b)]:=[(b,a)]$
*   Multiplication: $[(a,b)]\times[(c,d)]:=[(ac+bd,\;ad+bc)]$
*   Unity: $1_{\mathbb{Z}}:=[(1,0)]$
*   Order: $[(a,b)]\leq[(c,d)]\iff a+d\leq b+c$

$(\mathbb{Z},+,\times,\leq)$ forms an ordered commutative ring. Every element possesses an additive inverse, yielding the additive symmetry about $0$. Periodic Mathematics interprets this as the algebraic source of displacement direction. Integers may be viewed as $\mathbb{Z}$-module vectors on a 1D lattice.

**Natural Embedding**: $n\mapsto[(n,0)]$ preserves additive and multiplicative structure.

### 2.3 Rational Numbers $\mathbb{Q}$

**Construction** Let $\mathbb{Z}^\times:=\mathbb{Z}\setminus\{0\}$. Define $\approx$ on $\mathbb{Z}\times\mathbb{Z}^\times$:
$(a,b)\approx(c,d) \iff a\times d = b\times c$

The rationals $\mathbb{Q}:=(\mathbb{Z}\times\mathbb{Z}^\times)/\approx$. Equivalence classes are denoted $\frac{a}{b}$.

**Operations**
*   Addition: $\frac{a}{b}+\frac{c}{d}:=\frac{a\times d+b\times c}{b\times d}$
*   Zero: $\frac{0}{1}$; Additive Inverse: $-\frac{a}{b}:=\frac{-a}{b}$
*   Multiplication: $\frac{a}{b}\times\frac{c}{d}:=\frac{a\times c}{b\times d}$
*   Unity: $\frac{1}{1}$; Multiplicative Inverse: if $a\neq 0$, $(\frac{a}{b})^{-1}:=\frac{b}{a}$
*   Order: $\frac{a}{b}>0\iff a\times b>0$, extending to total order.

$(\mathbb{Q},+,\times,\leq)$ forms an ordered field. Non-zero elements possess both additive inverses (0-symmetry) and multiplicative inverses, yielding multiplicative symmetry about $1$. Periodic Mathematics interprets this as the algebraic source of scaling direction—$x$ and $x^{-1}$ are symmetric about $1$, representing magnification and diminution respectively.

**Integer Embedding**: $n\mapsto\frac{n}{1}$.

### 2.4 Real Numbers $\mathbb{R}$

**Construction (Dedekind Cuts)** The reals $\mathbb{R}$ consist of all lower sets $L\subset\mathbb{Q}$ satisfying:
1.  $L\neq\emptyset$, $L\neq\mathbb{Q}$.
2.  $L$ has no greatest element.
3.  If $x\in L$ and $y\in\mathbb{Q}$ with $y<x$, then $y\in L$ (downward closure).

A rational $q$ corresponds to the cut $\{x\in\mathbb{Q}\mid x<q\}$.

**Operations**
*   Order: $r\leq s\iff L_r\subseteq L_s$
*   Addition: $L_{r+s}:=\{x+y\mid x\in L_r,\;y\in L_s\}$
*   Multiplication: Defined first for positives as $\{xy\mid x\in L_r,y\in L_s,x,y>0\}\cup\mathbb{Q}_{\leq 0}$, extended by sign.

$\mathbb{R}$ satisfies the least upper bound property (completeness). Reals retain additive/multiplicative inverses and introduce continuity.

### 2.5 Complex Numbers $\mathbb{C}$

**Construction** $\mathbb{C}:=\mathbb{R}^2$. Addition is component-wise; multiplication is defined:
$(a,b)\times(c,d):=(ac-bd,\;ad+bc)$

Denote $a+bi:=(a,b)$, $i:=(0,1)$, whence $i^2=-1$.

**Algebraic Structure** $\mathbb{C}$ is a 2D commutative $\mathbb{R}$-algebra and a field. Every non-zero complex has inverse $(a+bi)^{-1}=\frac{a-bi}{a^2+b^2}$.

**Polar Form and Rotational Symmetry**
Any $z\in\mathbb{C}$ may be written $z=re^{i\theta}$, where $r=|z|=\sqrt{a^2+b^2}$ is the modulus and $\theta$ the argument. Multiplication $z\mapsto e^{i\phi}z$ preserves modulus whilst increasing the argument by $\phi$, i.e., a plane rotation. The unit complex group $\{e^{i\theta}\}$ is isomorphic to $U(1)$. Periodic Mathematics interprets this as the algebraic carrier of phase rotation direction.

### 2.6 Quaternions $\mathbb{H}$

**Construction** The quaternions $\mathbb{H}:=\mathbb{R}^4$, with elements $q=a+bi+cj+dk$. Addition is component-wise. Multiplication extends bilinearly from:
*   $i^2=j^2=k^2=ijk=-1$
*   $ij=k,\; ji=-k$; $jk=i,\; kj=-i$; $ki=j,\; ik=-j$

Multiplication is associative but non-commutative. $\mathbb{H}$ is a non-commutative $\mathbb{R}$-division algebra.

**Conjugate and Norm** $\bar{q}:=a-bi-cj-dk$, $|q|:=\sqrt{a^2+b^2+c^2+d^2}$. Inverse of non-zero: $q^{-1}=\bar{q}/|q|^2$.

**Rotational Symmetry** The unit quaternions $S^3$ are isomorphic to $SU(2)$. Rotation in 3D is effected via $v\mapsto qvq^{-1}$ ($v$ a pure imaginary quaternion). The non-commutativity of rotations about different axes corresponds to the non-commutativity of quaternion multiplication.

### 2.7 Overview of Number Systems and Symmetry Centres

| Number System | New Symmetry Introduced | Interpretation in Periodic Mathematics |
| :--- | :--- | :--- |
| $\mathbb{N}$ | None | Pure magnitude |
| $\mathbb{Z}$ | Additive symmetry $x\mapsto -x$ (0-symmetry) | Displacement direction |
| $\mathbb{Q}$ | Multiplicative symmetry $x\mapsto x^{-1}$ (1-symmetry) | Scaling direction |
| $\mathbb{R}$ | Completion | Continuous intensity |
| $\mathbb{C}$ | $U(1)$ rotational symmetry | Phase rotation direction |
| $\mathbb{H}$ | $SU(2)$ non-abelian rotational symmetry | Spatial rotation direction |

Three special numbers recur throughout this hierarchy. **0** is the additive identity and centre of additive inversion—demarcating positive from negative. **1** is the multiplicative identity and centre of multiplicative inversion—demarcating magnification from diminution. **$i$** is the generator of the rotation group $U(1)$—multiplication by $i$ effects a $90^\circ$ rotation.

---

## Part III: Vectors

Vectors are elements of modules or vector spaces over a scalar field (or coefficient ring). Each number system, serving as a scalar field, naturally induces a corresponding directional structure.

### 3.1 Properties of Vectors over Various Number Systems

| Vector Type | Scalar Field | Norm Definition | Direction Representation | Physical Correspondence |
| :--- | :--- | :--- | :--- | :--- |
| Natural Vector | $\mathbb{N}^n$ | Sum of coordinates | Sequence advancement | Step counting |
| Integer Vector | $\mathbb{Z}^n$ | Manhattan distance or lattice norm | Sign and ratio of components | Lattice displacement, discrete shift |
| Rational Vector | $\mathbb{Q}^n$ | Euclidean norm | Ratio of components | Position after proportional scaling |
| Real Vector | $\mathbb{R}^n$ | $\sqrt{\sum x_i^2}$ | Angle with coordinate axes | Velocity, force, field strength |
| Complex Vector | $\mathbb{C}^n$ | $\sqrt{\sum \|z_i\|^2}$ | Argument and relative phase | EM wave amplitude/phase, quantum states |
| Quaternion Vector | $\mathbb{H}^n$ | $\sqrt{\sum \|q_i\|^2}$ | Axis and angle of rotation | 3D rotation, rigid body attitude |

### 3.2 Vector Relations and Operations

| Concept | Mathematical Meaning | Directional Association | Characteristics |
| :--- | :--- | :--- | :--- |
| **Addition** | Component-wise sum | Composition of displacement | Commutative, associative |
| **Subtraction** | Component-wise difference | Decomposition of displacement | Addition of inverse |
| **Scalar Multiplication** | Multiply all components by scalar | Scaling direction (controlled by 1-symmetry) | Alters magnitude; preserves/reverses direction |
| **Dot Product (Inner)** | $\vec{a}\cdot\vec{b} = \sum a_i b_i$ | Magnitude of directional projection | Commutative; scalar result; zero if orthogonal |
| **Projection** | $\operatorname{proj}_{\vec{b}}\vec{a} = \frac{\vec{a}\cdot\vec{b}}{\vec{b}\cdot\vec{b}}\vec{b}$ | Directional decomposition | Collinear with $\vec{b}$ |
| **Cross Product** | $0$ / Scalar $ad-bc$ / Vector | Measure of rotational direction | Anticommutative |
| **Complex/Quaternion Product** | Rotation and scaling | Composition of phase/spatial rotation | Non-commutative (quaternions) |
| **Real/Imaginary Parts** | Extract linear/rotational components | Separates displacement from rotation | Projection operation |
| **Normalisation** | Divide vector by its norm | Extract unit direction | Magnitude becomes 1 |
| **Parallel/Perpendicular** | Proportionality / Zero dot product | Directional agreement / Orthogonality | Angle $0^\circ$ or $90^\circ$ |
| **Angle/Distance** | Arg. diff. or Euclidean angle / Norm of difference | Directional disparity / Displacement magnitude | Satisfies triangle inequality |
| **Propagation** | Evolution of vector field over time | Temporal evolution of direction | Governed by grad, div, curl |
| **Reflection/Refraction** | Mirror across normal / Directional deflection | Reversal/deflection of displacement | Incident angle = reflected angle / Snell's Law |

---

## Part IV: The Periodic System

A core innovation of Periodic Mathematics is elevating "periodicity" from a property of functions to a group action structure on a state set. The following definitions employ standard terminology from group and representation theory.

### 4.1 Group-Theoretic Determination of Periodic Relations

**Definition 3 ($G$-Periodicity)**
Let $S$ be a set and $G$ a transformation group acting on $S$. If there exists a subset $F\subset S$ (fundamental domain) such that every element of $S$ is obtained by applying some $g \in G$ to some $f \in F$, and distinct orbits are disjoint:
$$S = \bigsqcup_{f\in F} G\cdot f,$$
then $S$ is said to possess $G$-periodicity relative to $F$. Elements of $F$ are **symmetric points**, and $G$ is the **period group**. Periodic structure is the invariant of the group action; a periodic function is merely a representation thereof.

**Definition 4 (Periodic Function—Representation-Theoretic Form)**
Let $S$ admit $G$-periodicity, $V$ a vector space, and $\rho: G\to\text{GL}(V)$ a representation. If $\psi: S\to V$ satisfies
$$\psi(g\cdot s) = \rho(g)\psi(s),$$
then $\psi$ is a periodic function with respect to $G$. $\rho=\text{id}$ corresponds to ordinary periodic functions; $\rho\neq\text{id}$ corresponds to covariant periodic functions (e.g., Bloch waves).

**Definition 5 (Remainder as Periodic Function)**
Let $m \in \mathbb{N}^+$. The quotient set $\mathbb{Z}/m\mathbb{Z}$ forms the cyclic group $\mathbb{Z}_m$ of order $m$. The map
$$r_m: \mathbb{Z} \to \mathbb{Z}_m, \quad r_m(n) = n \bmod m$$
satisfies $r_m(n+m) = r_m(n)$ and is a discrete periodic function under the integer translation group action. The remainder folds the infinite integer sequence onto an orbit of a finite cyclic group.

### 4.2 Parameters of Periodic Measure

| Parameter | Symbol | Mathematical Definition | Physical Meaning |
| :--- | :--- | :--- | :--- |
| **Period Length** | $p$ | Least $p>0$ s.t. $f(\tau+p)=f(\tau)$, or generator step | Span of parameter for one complete cycle |
| **Frequency** | $f$ | $f = 1/p$ | Cycles per unit parameter |
| **Angular Frequency** | $\omega$ | $\omega = 2\pi f = 2\pi/p$ | Angular velocity of phase change |
| **Sample Count** | $n$ | Number of discrete observations per period | Degree of discretisation |
| **Sampling Interval** | $\Delta t$ | $\Delta t = p/n$ | Parameter span between samples |
| **Sampling Rate** | $f_s$ | $f_s = 1/\Delta t = n/p$ | Samples per unit parameter |
| **Phase** | $\phi$ | Offset relative to fundamental domain, $\phi \in [0, 2\pi)$ or $[0, p)$ | Initial position of oscillation |
| **Amplitude** | $A$ | $A = \sup_{\text{one period}} \|\psi - \bar{\psi}\|$ | Energy intensity |

### 4.3 Classification of Periods and Orbits

**Definition 6 (Static Period)**
If the period group $G$ is a cyclic group $G = \langle g \rangle$ (or direct product of cyclic groups), and the generator action is an isometric translation—i.e., $\exists p > 0$ s.t. $\forall s \in S, d(s, g\cdot s) = p$—then $S$ possesses a static (fixed) period, with $p$ as the minimal period. The remainder function $n \mapsto n \bmod m$ is the discrete prototype.

**Definition 7 (Dynamic Period)**
If the generator action distance is not constant, i.e., $\exists$ a local period function $p: S \to \mathbb{R}_{>0}$ s.t. $d(s, g\cdot s) = p(s)$ and $p(s)$ is not constant, then $S$ possesses a dynamic period. Applicable to locally periodisable systems. Lie group formulation: $\exists X \in \mathfrak{g}$ and smooth scale function $\lambda: S \to \mathbb{R}^+$ s.t. the infinitesimal action is $s \mapsto \exp(\lambda(s)X) \cdot s$.

**Definition 8 (Series Period)**
If the local period function $p(s)$ admits a Fourier series expansion $p(s) = p_0 + \sum (a_n\cos\frac{2\pi ns}{P} + b_n\sin\frac{2\pi ns}{P})$, the system possesses a series period. Vanishes to static period if all $a_n = b_n = 0$.

**Definition 9 (Infinite Orbit)**
If the transformation group $G$ is non-compact (e.g., $\mathbb{Z}$ or $\mathbb{R}$), and the orbit extends infinitely in one direction without returning to the start, the system possesses an infinite orbit. Examples include natural number sequences and hyperbolic trajectories. *Note*: Traditionally, "period" implies closed orbits. Periodic Mathematics unifies closed periods and infinite orbits under a generalised periodic structure.

**Definition 10 (Attracting Orbit)**
If an orbit approaches a limit point $s_*$ with self-similarity—i.e., $\exists 0 < \lambda < 1$ s.t. $d(g^{k+1}\cdot s, s_*)/d(g^k \cdot s, s_*) \to \lambda$—the system possesses an attracting orbit. The geometric sequence $\{r^n\}$ ($0 < r < 1$) is the elementary instance.

### 4.4 Period Combination and Resonance

**Definition 11 (Period Combination)**
If a system comprises two independent periodic processes (groups $G_1, G_2$, orders $n_1, n_2$), the coupled period group is a quotient of $G_1 \times G_2$, with order dividing $\operatorname{lcm}(n_1, n_2)$.

If $n_1/n_2 = m/k$ (irreducible fraction), the ratio $m:k$ is the **resonance ratio**, and $|m-k|$ is the **resonance order**. Lower-order resonances are more stable. Astronomical instance: The $1:2:4$ period ratios of Jupiter's Galilean moons.

---

## Part V: General Periodic Functions for Each Number System

Periodic Mathematics establishes general periodic functions for each number system, revealing the intrinsic link between number system structure and periodic behaviour.

### 5.1 Periodic Functions on Naturals

**Definition 12 (Periodic Sequence on Naturals)**
$f: \mathbb{N} \to V$ is **eventually periodic** if $\exists p$ s.t. $f(n+p)=f(n)$ for all sufficiently large $n$. If true for all $n$, it is **purely periodic**. Periodicity on naturals is "unidirectional", representing infinite orbits in discrete form.

### 5.2 Periodic Functions on Integers

**Definition 13 (Periodic Function on Integers)**
$f: \mathbb{Z} \to V$ is periodic with period $p$ if $f(n+p)=f(n)$ for all $n\in\mathbb{Z}$. General form: $f(n)=g(n \bmod p)$, where $g:\mathbb{Z}_p \to V$. The remainder function is the elementary example.

### 5.3 Periodic Functions on Rationals

**Definition 14 (Additive Periodic Function on Rationals)**
$f: \mathbb{Q} \to V$ satisfies $f(x+q)=f(x)$; the period group is $q\mathbb{Z}$.

**Definition 15 (Multiplicative Periodic Function on Rationals)**
$f: \mathbb{Q}^+ \to V$ satisfies $f(rx)=f(x)$, $r\neq 1$; the period group is the multiplicative group $\langle r \rangle$. The geometric sequence $f(k)=r^k$ is the elementary instance of an orbit under the multiplicative group.

### 5.4 Periodic Functions on Reals

**Definition 16 (Periodic Function on Reals)**
$f: \mathbb{R} \to V$ satisfies $f(t+T)=f(t)$. General form: $f(t)=\sum c_n e^{i 2\pi n t/T}$, i.e., the decomposition into irreducible representations of $U(1)$.

### 5.5 Periodic Functions on Complex Numbers

**Definition 17 (Elliptic Periodic Functions on Complex Numbers)**
$f(z+\omega_1)=f(z+\omega_2)=f(z)$, with $\omega_1,\omega_2$ $\mathbb{R}$-linearly independent; corresponds to elliptic functions.

**Definition 18 (Rotational Periodic Functions on Complex Numbers)**
$f(qz)=f(z)$, $q=e^{i\theta}$, $\theta/2\pi \in \mathbb{Q}$; the period group is a finite cyclic group.

### 5.6 Periodic Functions on Quaternions

**Definition 19 (Rotational Periodic Functions on Quaternions)**
$f(qxq^{-1})=f(x)$, $q$ a unit quaternion; the period group is $\langle q \rangle \subset SU(2)$. General form given by the Peter-Weyl theorem:
$$f(x) = \sum_{j=0}^{\infty} \sum_{m,n=-j}^{j} c_{mn}^j \, D_{mn}^j(x),$$
where $D_{mn}^j$ are the Wigner D-matrix elements of order $j$ for $SU(2)$.

---

## Part VI: Mathematical Apparatus

Periodic Mathematics directly employs standard tools of modern mathematics without reinvention.

### 6.1 Harmonic Analysis

Fourier series, Fourier transform, DFT/FFT (base-2/3/5/7 decompositions), wavelet transform, Laplace transform, Chirp Z-transform, etc., are unified as harmonic analysis on locally compact groups (Pontryagin duality, Peter-Weyl theorem). Periodic Mathematics reformulates this: periodic functions are expanded according to the irreducible representations of the period group.

| Period Group | Integral Transform |
| :--- | :--- |
| $U(1)$ | Fourier Series |
| $\mathbb{R}$ | Fourier Transform |
| $\mathbb{Z}_N$ | Discrete Fourier Transform (DFT) |
| $\mathbb{R}\rtimes\mathbb{R}^\times$ | Wavelet Transform |
| $\mathbb{R}_{\ge 0}$ | Laplace Transform |

### 6.2 Group Theory and Representation Theory

Group actions, orbits, fundamental domains, and equivariant maps constitute the core language for defining periodic structures.

### 6.3 Partial Differential Equations and Differential Geometry

Diffusion equations, wave equations, Ginzburg-Landau equations, etc., are standard tools for describing field evolution. Lie groups and algebras describe dynamic periodicity.

---

## Part VII: Gradient, Divergence, Curl, and the Quaternion Maxwell Equations

### 7.1 Gradient, Divergence, Curl

The gradient $\nabla\phi = (\partial_{x_1}\phi,\dots,\partial_{x_n}\phi)$ points in the direction of maximal increase of a scalar field. The divergence $\nabla\cdot\mathbf{F} = \sum \partial_i F_i$ measures the source/sink strength of a vector field. The curl $\nabla\times\mathbf{F}$ (vector in 3D, scalar in 2D) measures the local rotational intensity of a vector field.

> **Interpretive Note (Not a Theorem)**: Within the interpretive framework of Periodic Mathematics, the gradient associates with 0-symmetry (potential difference driving displacement), divergence with 1-symmetry (source/sink ratio defining scaling), and curl with $i$-symmetry (2D curl corresponds to complex phase rotation; 3D curl corresponds to the imaginary part of quaternion algebra).

### 7.2 Quaternion Gradient Operator and Maxwell's Equations

Introduce the quaternion gradient operator $\nabla = i\partial_x + j\partial_y + k\partial_z$. For a quaternion field $F = \mathbf{E} + i\mathbf{B}$, Maxwell's equations assume the compact quaternion form:
$$\nabla F = \rho - \mathbf{J},$$
where $\rho$ is charge density and $\mathbf{J}$ is current density. Expansion yields Gauss's law ($\nabla\cdot\mathbf{E} = \rho$) in the real part, and the Ampère-Maxwell law ($-\nabla\times\mathbf{B} + \frac{\partial\mathbf{E}}{\partial t} = -\mathbf{J}$) in the imaginary part. This formulation unifies gradient, divergence, and curl within the non-commutative structure of quaternion multiplication.

### 7.3 Operators and Symmetry Centres

| Operator | Field-Theoretic Role | Quaternion Expression | Symmetry Interpretation |
| :--- | :--- | :--- | :--- |
| **Gradient** | Potential-driven displacement | $\nabla\phi$ (scalar field) | 0-symmetry (Displacement direction) |
| **Divergence** | Source/Sink measure | $\operatorname{Re}(\nabla F)$ (scalar part) | 1-symmetry (Scaling direction) |
| **Curl** | Rotational measure | $\operatorname{Im}(\nabla F)$ (vector part) | $i$-symmetry (Phase rotation) |

> This association belongs to theoretical interpretation within the Periodic Mathematics framework, not an established mathematical theorem.

---

## Part VIII: Waves and Spectra—Computation via Categorical Operations

Wave propagation and spectral analysis are central applications of Periodic Mathematics. Starting from kernel functions, all spectral operations are decomposed into five independent categories: Group Actions (unary transformations), Interactions (multivariate coupling), Representation Transforms (basis changes), Domain Transforms (change of domain), and Projections & Selections (dimensionality reduction and compression). These five categories exhaust the fundamental operations on frequency, phase, period, and amplitude.

### 8.1 Kernel Functions

Kernel functions describe how local perturbations propagate spatially over time, or how signals are smoothed and reconstructed in transform domains. In periodic space $\mathfrak{P}_T$, kernels expand as multiplicative operators on irreducible representations: $K(x) = \sum_{\chi \in \widehat{G}} \hat{K}(\chi) \chi(x)$.

| Kernel | Mathematical Form | Physical/Informational Meaning | Effect on Period/Spectrum |
| :--- | :--- | :--- | :--- |
| **Gaussian** | $e^{-x^2/2\sigma^2}$ | Heat diffusion, Gaussian smoothing | High-frequency attenuation; period smoothing |
| **Exponential** | $e^{-\lambda\|x\|}$ | Radioactive decay, unilateral diffusion | Exponential amplitude decay along orbit |
| **Inverse Distance** | $1/\|x\|$ | Gravitational/electrostatic potential | Long-range correlation; long-range order |
| **Cauchy** | $1/(1+x^2)$ | Lorentzian line shape, heavy tails | Preserves long-range correlation; robust to outliers |
| **Triangular** | $1-\|x\|$ (compact support) | Linear interpolation, local averaging | Local smoothing; detail preservation |
| **Sinc** | $\sin(x)/x$ | Ideal low-pass filter | Rectangular window in freq.; total high-freq removal |
| **Bessel** | $J_0(x)$ | Cylindrical wave, radial diffusion | Suited for circular/cylindrical periodic domains |
| **Laplacian** | $e^{-\sqrt{x^2}}$ | Edge detection, singularity capture | Period boundary sharpening |
| **Hyperbolic Secant** | $\operatorname{sech}(x)$ | Soliton-like propagation | Preserves specific waveform |
| **Mexican Hat** | $(1-x^2)e^{-x^2/2}$ | Edge enhancement (LoG) | Extracts period transition points |

### 8.2 Categorical Classification of Spectral Operations

#### Category I: Group Actions
Unary transformations preserving the representation space; the action of a group on the function space of spectra.

| Group Action | Group | Mathematical Definition | Physical Meaning |
| :--- | :--- | :--- | :--- |
| **Frequency Shift** | $(\mathbb{R},+)$ | $(T_a \hat{\psi})(\omega) = \hat{\psi}(\omega - a)$ | Modulation; spectrum translation |
| **Frequency Scaling** | $(\mathbb{R}^+,\times)$ | $(S_\lambda \hat{\psi})(\omega) = \hat{\psi}(\omega/\lambda)$ | Time compression/expansion |
| **Phase Rotation** | $U(1)$ | $(R_\phi \hat{\psi})(\omega) = e^{i\phi} \hat{\psi}(\omega)$ | Global phase shift; time delay |
| **Amplitude Gain** | $C(\Omega,\mathbb{R}^+)$ | $(A_g \hat{\psi})(\omega) = g(\omega)\hat{\psi}(\omega)$ | Filtering; selective amplification/attenuation |
| **Freq. Axis Reflection** | $C_2$ | $(M \hat{\psi})(\omega) = \hat{\psi}(-\omega)$ | Spectrum reversal; time-domain conjugation |

#### Category II: Interactions
Binary or multivariate operations between two (or more) periodic structures, generating new frequency components. This is a distinctive direction of Periodic Mathematics versus traditional harmonic analysis.

| Interaction | Mathematical Definition | Physical Meaning | New Period Generated |
| :--- | :--- | :--- | :--- |
| **Linear Superposition** | $(\hat{\psi}_1 + \hat{\psi}_2)(\omega)$ | Interference | No new frequencies; amplitude/phase change only |
| **Frequency Convolution** | $(\hat{\psi}_1 * \hat{\psi}_2)(\omega)$ | Mixing; time-domain product | Sum freq. $\omega_1+\omega_2$, diff. freq. $\|\omega_1-\omega_2\|$ |
| **Pointwise Product** | $(\hat{\psi}_1 \cdot \hat{\psi}_2)(\omega)$ | Frequency-domain windowing; time conv. | Frequency gating |
| **Inner Product/Correlation** | $\langle \hat{\psi}_1, \hat{\psi}_2 \rangle$ | Matched filtering; coherence measure | Scalar match metric |

#### Category III: Representation Transforms
Changing the signal's basis, mapping from one Hilbert space to another.

| Representation Transform | Original Space | Target Space | Core Property |
| :--- | :--- | :--- | :--- |
| **Fourier Transform** | $L^2(\mathbb{R}, dt)$ | $L^2(\mathbb{R}, d\omega)$ | Diagonalises translation group |
| **Short-Time FT** | $L^2(\mathbb{R})$ | $L^2(\mathbb{R}^2)$ | Local frequency analysis |
| **Wavelet Transform** | $L^2(\mathbb{R})$ | $L^2(\mathbb{R} \times \mathbb{R}^+)$ | Diagonalises affine group |
| **Laplace Transform** | Time-domain function | Complex frequency domain | Growth/decay mode decomposition |
| **Z-Transform** | Discrete sequence | Unit circle in complex plane | Frequency response of discrete systems |
| **Spherical Harmonics** | $L^2(S^2)$ | Sequence of harmonic coefficients | Diagonalises $SO(3)$ rotation group |

#### Category IV: Domain Transforms
Altering the underlying variable set itself—from continuous to discrete, uniform to non-uniform.

| Domain Transform | Mathematical Definition | Physical Meaning |
| :--- | :--- | :--- |
| **Sampling** | $\psi[n] = \psi(n\Delta t)$ | Continuous→Discrete; restriction to $\Delta t \mathbb{Z}$ |
| **Interpolation/Recon.** | $\psi(t) = \sum_n \psi[n] \operatorname{sinc}(t-n\Delta t)$ | Discrete→Continuous |
| **Resampling** | Alter $\Delta t$ (decimation/interpolation) | Change step size of discrete subgroup |
| **Periodic Continuation** | $\psi_{\text{per}}(t) = \sum_k \psi(t - kT)$ | From aperiodic to periodic |

> **Pontryagin Duality Perspective**: Sampling is the restriction from the continuous group $\mathbb{R}$ to its discrete subgroup $\Delta t\mathbb{Z}$. The Fourier transform maps this restriction to a periodic continuation on the dual group $U(1)$. This is the group-theoretic essence of the sampling theorem.

#### Category V: Projections and Selections
Selecting a subset from the full spectrum, or projecting a high-dimensional representation onto a lower-dimensional subspace.

| Projection/Selection | Mathematical Definition | Physical Meaning |
| :--- | :--- | :--- |
| **Band-pass Filter** | $\hat{\psi}' = \hat{\psi} \cdot \mathbf{1}_{[\omega_1,\omega_2]}$ | Select specific frequency band |
| **Downsampling (Decim.)** | Retain every $M$-th sample; discard others | Reduce data rate |
| **Principal Component Anal.** | Project onto direction of max. variance | Dimensionality reduction; extract dominant modes |
| **Threshold Compression** | Retain $\|\hat{\psi}\|>\tau$ components; zero others | Sparse representation |

### 8.3 Constructing Complex Operations from Basic Ones

| Complex Operation | Construction Method | Categories Involved |
| :--- | :--- | :--- |
| **Translation** | Frequency-dependent phase rotation | Group Action (Phase Rotation) |
| **Scaling** | Inverse of frequency scaling | Group Action (Frequency Scaling) |
| **Filtering** | Amplitude gain $g(\omega)$ | Group Action (Amplitude Gain) |
| **Convolution** | Frequency-domain product | Group Action (Amplitude Gain + Phase Rotation) |
| **Diffusion** | Multiplication by Gaussian transfer fn. | Group Action (Amplitude Gain) |
| **Perturbation** | Additive source | Interaction (Superposition) |
| **Sampling** | Time sampling ↔ Freq. periodisation | Domain Transform (Sampling) + Group Action |
| **Resampling** | Interpolation + Decimation | Domain Transform + Group Action (Amplitude Gain) |
| **Transformation** | Basis change | Representation Transform |
| **Fund./Beat Freq.** | Generation of difference frequency | Interaction (Freq. Convolution) |
| **Resonance** | Gain peak + Sum frequency | Group Action (Amplitude Gain) + Interaction |
| **Coupling** | Product term ↔ Freq. convolution | Interaction (Freq. Convolution) |
| **Suppression** | Notch filtering | Group Action (Amplitude Gain) |
| **Locking/Unlocking** | Phase feedback + Nonlinear attractor | Group Action (Phase Rotation) + Interaction |
| **Energy/dB** | $\int \|\hat{\psi}\|^2 d\omega$ | Metric of Group Action (Amplitude Gain) |
| **Entropy** | $-\sum p_i \log p_i$ | Projection (Probability) + Metric |
| **Compression** | Transform + Threshold + Coding | Repr. Transform + Projection (Threshold) |
| **Freq. Clustering** | Distance metric on spectrum + Grouping | Group Action (Freq. Shift) + Metric |
| **Freq. Division Multiplex.** | Modulate multi-ch. signals to diff. bands | Group Action (Frequency Shift) |

**Core Perspective of Periodic Mathematics**: All operations above reduce to combinations of frequency, phase, period, and amplitude manipulations across the five basic categories. The **Interaction** category distinguishes Periodic Mathematics from traditional harmonic analysis—it focuses on how different periods generate new periods, resonance, locking, and annihilation through coupling.

---

## Part IX: Perturbations, Coupling, and Interference

Perturbations are the fundamental drivers of dynamic evolution in periodic systems.

### 9.1 Point Perturbations

**Definition 20 (Point Perturbation)**
A perturbation injected at location $x_0$: $\psi'(x) = \psi(x) + \varepsilon \cdot \delta(x - x_0)$, where $\varepsilon \in \mathbb{C}$ is the intensity.

### 9.2 Interference

Superposition of two perturbations yields an interference term: $|\psi_1+\psi_2|^2 = |\psi_1|^2+|\psi_2|^2+2|\psi_1||\psi_2|\cos(\Delta\phi)$. In-phase enhances; anti-phase cancels.

### 9.3 Effects of Perturbations on Periodic Structure

| Effect Dimension | Mathematical Characterisation | Physical Manifestation |
| :--- | :--- | :--- |
| **Period Change** | Period group changes to subgroup or quotient | Rhythm reset |
| **Amplitude Change** | Smoothing or sharpening via diffusion kernel | Energy decay or amplification |
| **Frequency Change** | Excitation of new frequency components | Spectral broadening |

---

## Conclusion

Periodic Mathematics grounds itself in symmetry and directionality, taking the hierarchical ascent of symmetry groups during number system extension as its leitmotif. It defines periodicity via orbit decomposition under group actions and establishes corresponding general periodic functions for each number system. Gradient, divergence, and curl acquire unified expression through the quaternion Maxwell equations, linking interpretively to the three symmetry centres 0, 1, and $i$. Operations on waves and spectra are described categorically across five domains—Group Actions, Interactions, Representation Transforms, Domain Transforms, and Projections & Selections—with Interactions being the distinctive focus, examining how diverse periods generate novel periods, resonance, locking, and annihilation through coupling. The framework fully incorporates standard modern mathematical constructions, aiming to provide a unified mathematical language for periodic phenomena.

---

<div align="center">

### Periodic Mathematics

© 2026 Fuzi

**Licence: MIT**

</div>

---
