ARCHS = armv7 arm64
export TARGET = iphone:clang:7.1:7.1

include theos/makefiles/common.mk

BUNDLE_NAME = SmonCheats
SmonCheats_FILES = SmonCheats.mm
SmonCheats_INSTALL_PATH = /Library/PreferenceBundles
SmonCheats_FRAMEWORKS = UIKit
SmonCheats_PRIVATE_FRAMEWORKS = Preferences

include $(THEOS_MAKE_PATH)/bundle.mk

internal-stage::
	$(ECHO_NOTHING)mkdir -p $(THEOS_STAGING_DIR)/Library/PreferenceLoader/Preferences$(ECHO_END)
	$(ECHO_NOTHING)cp entry.plist $(THEOS_STAGING_DIR)/Library/PreferenceLoader/Preferences/SmonCheats.plist$(ECHO_END)
