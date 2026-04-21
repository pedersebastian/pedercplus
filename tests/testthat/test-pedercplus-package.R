test_that("to_lower-versjonene gir samme resultat", {
  input <- "Hello World 123"
  expected <- "hello world 123"
  expect_equal(to_lower_v1(input), expected)
  expect_equal(to_lower_v2(input), expected)
  expect_equal(to_lower_v3(input), expected)
})

test_that("to_lower håndterer allerede små bokstaver", {
  expect_equal(to_lower_v1("abc"), "abc")
  expect_equal(to_lower_v2("abc"), "abc")
  expect_equal(to_lower_v3("abc"), "abc")
})

test_that("ar1_cpp returnerer vektor av riktig lengde", {
  x <- ar1_cpp(100, phi = 0.9, sigma = 1)
  expect_length(x, 100)
})

test_that("ar1_cpp starter på 0", {
  x <- ar1_cpp(50, phi = 0.5, sigma = 1)
  expect_equal(x[1], 0)
})

test_that("ar1_cpp med phi=0 gir ukorrelert støy", {
  set.seed(42)
  x <- ar1_cpp(1000, phi = 0, sigma = 1)
  expect_lt(abs(cor(x[-1], x[-length(x)])), 0.1)
})
