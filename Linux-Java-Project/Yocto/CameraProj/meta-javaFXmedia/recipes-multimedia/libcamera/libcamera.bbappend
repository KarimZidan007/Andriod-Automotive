# meta-yourlayer/recipes-multimedia/libcamera/libcamera_%.bbappend

# Append custom Meson options
EXTRA_OEMESON += " \
    -Dpipelines=rpi/vc4,rpi/pisp \
    -Dipas=rpi/vc4,rpi/pisp \
    -Dv4l2=true \
    -Dgstreamer=enabled \
    -Dtest=false \
    -Dlc-compliance=disabled \
    -Dcam=disabled \
    -Dqcam=disabled \
    -Ddocumentation=disabled \
    -Dpycamera=enabled \
"

# Set GST_PLUGIN_PATH environment variable
EXTRA_ENV += "GST_PLUGIN_PATH=${B}/${D}${libdir}/gstreamer-1.0"

# Override the do_configure task to use the custom Meson options
do_configure[prepend] = "meson setup ${B} --buildtype=release ${EXTRA_OEMESON}"

# Override the do_compile task to use the custom Ninja build command
do_compile() {
    ninja -C ${B}
}

# Override the do_install task to install the compiled binaries
do_install() {
    ninja -C ${B} install
}

