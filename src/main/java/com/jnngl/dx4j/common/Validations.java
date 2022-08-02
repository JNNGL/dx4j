package com.jnngl.dx4j.common;

import java.util.Objects;

public class Validations {

  public static void validateNotNull(Object obj) {
    Objects.requireNonNull(obj, "obj == null");
  }

  public static void validateArrayLength(Object arr, int len) {
    validateNotNull(arr);
    if (((Object[]) arr).length < len) {
      throw new IllegalStateException("arr.length < " + len);
    }
  }

}
