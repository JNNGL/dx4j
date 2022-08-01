package com.jnngl.dx4j;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;

public class Dx4j {

  private static boolean loaded = false;

  public static void loadLibrary() {
    if (!loaded) {
      try {
        // Load from java.library.path
        System.loadLibrary("dx4j");
      } catch (UnsatisfiedLinkError e) {
        File tempFile;
        try(InputStream inputStream = Dx4j.class.getResourceAsStream("/dx4j.dll");
            OutputStream out = new FileOutputStream(
                tempFile = File.createTempFile("dx4j_native", ".dll"))) {
          // Copy native library to temp file
          assert inputStream != null;
          out.write(inputStream.readAllBytes());
          tempFile.deleteOnExit();
        } catch (IOException ex) {
          throw new RuntimeException(ex);
        }
        // Load native library from temp file
        System.load(tempFile.getAbsolutePath());
      }
      loaded = true;
    }
  }

  public static native String helloWorld();

}
