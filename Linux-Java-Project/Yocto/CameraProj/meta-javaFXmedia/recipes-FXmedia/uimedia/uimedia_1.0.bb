DESCRIPTION ="this Recipe Contain all Dependencies to Run JAVAFX UI Supporting Camera using opencv approach , Camera with gStreamer, MediaPlayer"
SUMMARY = "UI Application Dependencies Only"
LICENSE = "CLOSED"
AUTHOR ="ENG:KAREEM.ZIDAN"

# Build dependencies
DEPENDS += "ffmpeg gstreamer1.0 libogg libvorbis libtheora liba52 lame pulseaudio mesa libepoxy libva glew libfakekey matchbox-wm fontconfig \ 
	   freetype pango libpng jpeg tiff x264 libwebp xserver-xorg gstreamer1.0-omx vlc"

# Runtime dependencies
RDEPENDS_${PN} += "ffmpeg vlc libavcodec libavformat  libavutil libbz2 libgcc libmamera gtk+3 pulseaudio gstreamer1.0-plugins-base \
		    gstreamer1.0-plugins-good gstreamer1.0-plugins-bad gstreamer1.0-plugins-ugly \
                   libogg libvorbis libtheora liba52 lame pulseaudio mesa libepoxy libva glew libfakekey matchbox-wm \
                   fontconfig freetype pango libpng jpeg tiff x264 libwebp xserver-xorg gstreamer1.0-omx libcamera-devel"
PACKAGECONFIG += "gstreamer"


# Comment out the source section if not using any source code for now
# SRC_URI = "file://path_to_your_ui_sources"

# Disable packaging the application, only install dependencies
do_compile() {
    echo "Skipping compilation; only installing dependencies."
}

do_install() {
    echo "Skipping installation of application files; only managing dependencies."
}

PROVIDES="UI"
