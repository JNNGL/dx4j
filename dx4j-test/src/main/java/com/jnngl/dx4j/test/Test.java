package com.jnngl.dx4j.test;

import com.jnngl.dx4j.Dx4j;

class Test {

  public static void main(String[] args) {
    Dx4j.loadLibrary();
    System.out.println(Dx4j.helloWorld());
  }

}
