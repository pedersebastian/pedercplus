# Simuler en AR(1)-prosess

Hvert steg: x(t) = phi \* x(t-1) + støy. Fordi hvert steg avhenger av
forrige kan ikke R vektorisere dette.

## Usage

``` r
ar1_cpp(n, phi, sigma)
```

## Arguments

- n:

  Antall tidssteg

- phi:

  Autokorrelasjon (-1 til 1). 0.9 = treg mean-reversion

- sigma:

  Standardavvik på støyen

## Value

Numerisk vektor av lengde n

## Examples

``` r
set.seed(1)
x <- ar1_cpp(100, phi = 0.9, sigma = 1)
plot(x, type = "l")
```
