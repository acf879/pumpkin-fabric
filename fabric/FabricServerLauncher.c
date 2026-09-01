#include <fabric/loader.h>
#include <jni.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#if _WIN32
#include <windows.h>
#else

#endif

static int setup(void) {
  /*
   *         private static void setup(String... runArguments) throws
   * IOException { String path =
   * System.getProperty(SystemProperties.GAME_JAR_PATH);
   *
   *                 if (path == null) {
   *                         path = getServerJarPath();
   *                         System.setProperty(SystemProperties.GAME_JAR_PATH,
   *  path);
   *                 }
   *
   *                 Path serverJar = LoaderUtil.normalizePath(Paths.get(path));
   *
   *                 if (!Files.exists(serverJar)) {
   *                         System.err.println("The Minecraft server .JAR is
   *  missing
   * (" + serverJar + ")!"); System.err.println(); System.err.println("Fabric's
   * server-side launcher expects the server .JAR to be provided.");
   *                         System.err.println("You can edit its location in
   * fabric-server-launcher.properties."); System.err.println();
   *                         System.err.println("Without the official Minecraft
   * server .JAR, Fabric Loader cannot launch."); throw new
   *  RuntimeException("Missing game jar at " + serverJar);
   *                 }
   *         }
   * ------------------------------------------------------------------------
   *  The above is the setup in the java code
   *
   *    [[src/main/java/net/fabricmc/loader/impl/launch/server/FabricServerLauncher.java]]
   */
  return 0;
}

// NOTE: will call fabric_server_launcher.init() and then the main function from
// rust (patch will paste the C ABI code right above the typical pumpkin
// "start")
static int init(void) {
  // TODO: Check for existance of `fabric-server-launch.properties`
  // If it exists continue else generate it

  // TODO: Check if in development

  /*
   *                        URL propUrl =
   *     parentLoader.getResource("fabric-server-launch.properties");
   *
   *                if (propUrl != null) {
   *                        Properties properties = new Properties();
   *
   *                        try (InputStreamReader reader = new
   *     InputStreamReader(propUrl.openStream(), StandardCharsets.UTF_8)) {
   *                                properties.load(reader);
   *                        } catch (IOException e) {
   *                                e.printStackTrace();
   *                        }
   *
   *                        if (properties.containsKey("launch.mainClass")) {
   *                                mainClass =
   *     properties.getProperty("launch.mainClass");
   *                        }
   *                }
   *
   *                boolean dev =
   *     SystemProperties.isSet(SystemProperties.DEVELOPMENT);
   *
   *                if (!dev) {
   *                        try {
   *                                setup(args);
   *                        } catch (Exception e) {
   *                                throw new RuntimeException("Failed to setup
   *     Fabric server environment!", e);
   *                        }
   *                }
   *
   *                try {
   *                        Class<?> c = Class.forName(mainClass);
   *                        MethodHandles.lookup().findStatic(c, "main",
   *     MethodType.methodType(void.class, String[].class)).invokeExact(args); }
   *     catch (Throwable e) { throw new RuntimeException("An exception occurred
   *     when launching the server!", e);
   *                }
   *
   * ------------------------------------------------------------------------
   *  The above is the entry point in the java code
   *
   *    [[src/main/java/net/fabricmc/loader/impl/launch/server/FabricServerLauncher.java]]
   */
  return 0;
}

static int deinit(void) {
  // TODO: Free any allocated memory and do some cleanup
  return 0;
}

FabricServerLauncher fabric_server_launcher = {
    .init = init,
    .deinit = deinit,
};
