library(corrplot)
library(lmtest)

data <- read.csv(file = 'IRIS.csv')
frame <- data.frame(data)

frame <- transform(frame,
                   sepal_length = as.numeric(sepal_length),
                   sepal_width = as.numeric(sepal_width),
                   petal_length = as.numeric(petal_width))

without_na <- na.omit(frame)
dataframe <- data.frame(sepal_length = without_na$sepal_length,
                        sepal_width = without_na$sepal_width,
                        petal_length = without_na$petal_length)

sepal_length <- (dataframe$sepal_length)
sepal_width <- (dataframe$sepal_width)
petal_length <- (dataframe$petal_length)

dataframe <- data.frame(petal_length, sepal_width, sepal_length)
pairs(dataframe, pch = 1)

histogram_check <- function(dat){
  f <- summary(dat)$fstatistic
  p <- pf(f[1], f[2], f[3], lower.tail = F)
  attributes(p) <- NULL
  return(p)
}

model <- lm(petal_length ~ sepal_width + sepal_length, data = dataframe)
sqrt(summary(model)$r.squared)
histogram_check(model)

X = cbind(as.matrix(data.frame(sepal_width, sepal_length)))
solve(t(X) %*% X)

summary(model)
bptest(model)

weights <- 1 / lm(abs(model$residuals) ~ model$fitted.values)$fitted.values^2
weighted_model <- lm(petal_length ~ sepal_width + sepal_length, data = data, weights = weights)
summary(weighted_model)

confint(weighted_model)
qqnorm(weighted_model$residuals, ylab = "Похибки", xlab = "Теоретичні квантилі")
qqline(weighted_model$residuals, col = "blue", lwd = 2)
shapiro.test(weighted_model$residuals)
plot(weighted_model$fitted.values, weighted_model$residuals,
     col = "black", xlab = "Передбачені значення", ylab = "Похибки")


