fun luhnAlgorithm(cardNumber: String): Boolean {
    val digits = cardNumber.map { Character.getNumericValue(it) }.toMutableList()
    for (i in (digits.size - 2) downTo 0 step 2) {
        var value = digits[i] * 2
        if (value > 9) {
            value = value % 10 + 1
        }
        digits[i] = value
    }
    return digits.sum() % 10 == 0
}