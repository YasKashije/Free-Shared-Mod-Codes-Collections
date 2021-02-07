ARCHS = armv7 arm64
export TARGET = iphone:clang:7.1:8.1

include theos/makefiles/common.mk

TWEAK_NAME = SmonCheats
SmonCheats_FILES = Tweak.xm
SmonCheats_FRAMEWORKS = UIKit

include $(THEOS_MAKE_PATH)/tweak.mk


SUBPROJECTS += SmonCheats
include $(THEOS_MAKE_PATH)/aggregate.mk
