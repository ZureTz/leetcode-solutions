package algorithm

import (
	"strconv"
	"strings"
	"testing"

	"github.com/stretchr/testify/assert"
)

func TestAtoi(t *testing.T) {
	testStr := " 123  "
	_, err := strconv.Atoi(testStr)
	// Expect error
	assert.Error(t, err)

	testStrWithNoSpace := strings.Trim(testStr, " ")
	assert.Equal(t, testStrWithNoSpace, "123")
	number, err := strconv.Atoi(testStrWithNoSpace)
	// Expect no error
	assert.Equal(t, number, 123)
	assert.NoError(t, err)
}
