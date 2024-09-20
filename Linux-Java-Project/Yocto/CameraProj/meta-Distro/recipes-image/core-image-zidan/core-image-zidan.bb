DESCRIPTION = "core-image-zidan is an Image with Sato, a mobile environment and visual style for \
mobile devices. The image supports X11 with a Sato theme, Pimlico \
applications, and contains terminal, editor, and file manager."
AUTHOR="ENG:KAREEM.ZIDAN"

IMAGE_FEATURES += "splash package-management x11-base x11-sato ssh-server-dropbear hwcodecs x11 "

LICENSE = "MIT"

inherit core-image

inherit rm_work
# Build dependencies


DEPENDS += " libpthread-stubs ffmpeg gstreamer1.0 libogg libvorbis libtheora liba52 lame pulseaudio mesa libepoxy libva glew libfakekey\
	      matchbox-wm fontconfig freetype pango libpng jpeg tiff x264 libwebp xserver-xorg gstreamer1.0-omx vlc"




# Runtime dependencies
RDEPENDS_${PN} += " ffmpeg vlc libavcodec libavformat  libavutil libbz2 libgcc\
		     libcamera gtk+3 pulseaudio gstreamer1.0-plugins-base \
                    gstreamer1.0-plugins-good gstreamer1.0-plugins-bad gstreamer1.0-plugins-ugly \
                   libogg libvorbis libtheora liba52 lame pulseaudio mesa libepoxy libva glew libfakekey matchbox-wm \
                   fontconfig freetype pango libpng jpeg tiff x264 libwebp xserver-xorg libcamera-devel"


IMAGE_INSTALL += " vlc ffmpeg zlib gstreamer1.0 gstreamer1.0-plugins-good gstreamer1.0-plugins-bad gstreamer1.0-plugins-ugly \
                   libcamera dnf dnf-plugin-tui dnfdragora libdnf"


#Manual Copy of JAVAFX into /usr/lib
##############################

ROOTFS_POSTPROCESS_COMMAND += "copy_jfx_libraries; "

copy_jfx_libraries() {
    # Define the source directory where your libraries are located
    SRC_DIR="/home/karimzidantech/poky/FINAL_CAM/tmp-glibc/work/cortexa72-oe-linux/JAVAFX/1.1-r0/image/usr/lib/JAVAFX"
    
    # Define the destination directory in the root filesystem
    DEST_DIR="${IMAGE_ROOTFS}/usr/lib/"
    
    # Create the destination directory if it doesn't exist
    mkdir -p ${DEST_DIR}
    
    # Copy the libraries to the root filesystem
    cp -r ${SRC_DIR}/* ${DEST_DIR}/
}


###############################
IMAGE_NAME="zidan-rpi-sdimg"

IMAGE_FSTYPES="tar.xz ext3 rpi-sdimg"

TOOLCHAIN_HOST_TASK:append = " nativesdk-intltool nativesdk-glib-2.0"
TOOLCHAIN_HOST_TASK:remove:task-populate-sdk-ext = " nativesdk-intltool nativesdk-glib-2.0"

QB_MEM = '${@bb.utils.contains("DISTRO_FEATURES", "opengl", "-m 512", "-m 256", d)}'
QB_MEM:qemuarmv5 = "-m 256"
QB_MEM:qemumips = "-m 256"



