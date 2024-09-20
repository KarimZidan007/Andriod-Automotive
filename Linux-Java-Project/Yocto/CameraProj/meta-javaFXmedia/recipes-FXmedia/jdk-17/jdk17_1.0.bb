
DESCRIPTION = "Oracle JDK 17"
LICENSE = "Closed"

SRC_URI = "https://download.oracle.com/java/17/latest/jdk-17_linux-aarch64_bin.tar.gz"
SRC_URI[sha256sum] = "31c2fa06f3f98d92984a86269c71e6b9e956272084f3a1d2db6d07e6164b2f4f"

S = "${WORKDIR}/jdk-17.0.12"
DEPENDS="glibc "



do_unpack() {
    # Extract the tarball
    tar -xzf ${DL_DIR}/jdk-17_linux-aarch64_bin.tar.gz -C ${WORKDIR}
    rm -r ${S}/legal ${S}/man ${S}/jmods ${S}/include ${S}/README ${S}/release ${S}/LICENSE
}


do_install() {
    # Ensure the target directories exist
    install -d ${D}${bindir}
    install -d ${D}${libdir}
       # Install binaries
    cp -r ${S}/bin/* ${D}${bindir}/

    # Install libraries
    cp -r ${S}/lib/* ${D}${libdir}/
    # Install documentation (if applicable)

}
FILES:${PN} = "${bindir}/* ${libdir}/*.so* ${libdir}/jvm.cfg ${libdir}/jrt-fs.jar ${libdir}/psfont.properties.ja ${libdir}/modules\
         ${libdir}/jexec ${libdir}/security/cacerts ${libdir}/server/libjsig.so ${libdir}/server/libjvm.so ${libdir}/server/classes.jsa\
                 ${libdir}/server/classes_nocoops.jsa ${libdir}/tzdb.dat ${libdir}/src.zip ${libdir}/classlist ${libdir}/jspawnhelper\
                 ${libdir}/ct.sys ${libdir}/ct.sym ${libdir}/psfontj2d.properties ${libdir}/jfr ${libdir]/jfr/default.jfc ${libdir}/jfr/profile.jfc"

# Development package
PACKAGES += "${PN}-security"

FILES:${PN}-security = " \
    ${libdir}/security/* \
"


# Avoid license check since we are managing it ourselves
INSANE_SKIP:${PN} = "license"
INSANE_SKIP:${PN}:append = " dev-so"
do_populate_lic[noexec] = "1"
