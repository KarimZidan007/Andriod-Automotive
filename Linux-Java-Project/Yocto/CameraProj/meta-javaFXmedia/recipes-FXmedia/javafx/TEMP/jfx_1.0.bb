SUMMARY = "JAVAFX22- Recipe"
DESCRIPTION = "A recipe for JAVAFX22 from GitHub."
LICENSE = "CLOSED"

DEPENDS=+"gstreamer1.0 ffmpeg libcamera gtk+3 pango mesa freetype  xserver-xorg  libcam"


SRC_URI = "git://github.com/KarimZidan007/JAVAFX.git;protocol=https;branch=main"



SRCREV = "ce8b71579c612e5c1909ad6fb3ef3eebbc224fc0"




do_install () {
    install -d ${D}/usr/lib/jfx
    install -m 0755 ${WORKDIR}/git/JFX22/lib/* ${D}/usr/lib/jfx
}

PN = "jfx"

INSANE_SKIP:${PN} += "already-stripped"




FILES_${PN} += "/usr/lib"


