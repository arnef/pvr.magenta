/*
 *  Copyright (C) 2020 Team Kodi (https://kodi.tv)
 *
 *  SPDX-License-Identifier: GPL-2.0-or-later
 *  See LICENSE.md for more information.
 */

#include "Settings.h"
#include <kodi/General.h>

bool CSettings::Load()
{
  if (!kodi::addon::CheckSettingString("username", m_userName))
  {
    /* If setting is unknown fallback to defaults */
    kodi::Log(ADDON_LOG_ERROR, "Couldn't get 'username' setting");
    return false;
  }

  if (!kodi::addon::CheckSettingString("password", m_password))
  {
    /* If setting is unknown fallback to defaults */
    kodi::Log(ADDON_LOG_ERROR, "Couldn't get 'password' setting");
    return false;
  }

  if (!kodi::addon::CheckSettingString("epg_token", m_epgToken))
  {
    /* If setting is unknown fallback to defaults */
    kodi::Log(ADDON_LOG_ERROR, "Couldn't get 'epg_token' setting");
    return false;
  }

  if (!kodi::addon::CheckSettingString("openid_token", m_openidToken))
  {
    /* If setting is unknown fallback to defaults */
    kodi::Log(ADDON_LOG_ERROR, "Couldn't get 'openid_token' setting");
    return false;
  }

  if (!kodi::addon::CheckSettingString("tv_token", m_tvToken))
  {
    /* If setting is unknown fallback to defaults */
    kodi::Log(ADDON_LOG_ERROR, "Couldn't get 'tv_token' setting");
    return false;
  }

  if (!kodi::addon::CheckSettingString("refresh_token", m_refreshToken))
  {
    /* If setting is unknown fallback to defaults */
    kodi::Log(ADDON_LOG_ERROR, "Couldn't get 'refresh_token' setting");
    return false;
  }

  if (!kodi::addon::CheckSettingString("csrftoken", m_csrfToken))
  {
    /* If setting is unknown fallback to defaults */
    kodi::Log(ADDON_LOG_ERROR, "Couldn't get 'csrftoken' setting");
    return false;
  }

  if (!kodi::addon::CheckSettingString("personaltoken", m_personalToken))
  {
    /* If setting is unknown fallback to defaults */
    kodi::Log(ADDON_LOG_ERROR, "Couldn't get 'personaltoken' setting");
    return false;
  }

  if (!kodi::addon::CheckSettingString("deviceid", m_magentaDeviceID))
  {
    /* If setting is unknown fallback to defaults */
    kodi::Log(ADDON_LOG_ERROR, "Couldn't get 'deviceid' setting");
    return false;
  }

  if (!kodi::addon::CheckSettingInt("startnum", m_start_num))
  {
    /* If setting is unknown fallback to defaults */
    kodi::Log(ADDON_LOG_ERROR, "Couldn't get 'startnum' setting");
    return false;
  }

  if (!kodi::addon::CheckSettingBoolean("hideunsubscribed", m_hideunsubscribed))
  {
    /* If setting is unknown fallback to defaults */
    kodi::Log(ADDON_LOG_ERROR, "Couldn't get 'hideunsubscribed' setting");
    return false;
  }

  if (!kodi::addon::CheckSettingBoolean("customchannels", m_usecustomchannels))
  {
    /* If setting is unknown fallback to defaults */
    kodi::Log(ADDON_LOG_ERROR, "Couldn't get 'customchannels' setting");
    return false;
  }

  if (!kodi::addon::CheckSettingBoolean("whitelogos", m_whitelogos))
  {
    /* If setting is unknown fallback to defaults */
    kodi::Log(ADDON_LOG_ERROR, "Couldn't get 'whitelogos' setting");
    return false;
  }

  if (!kodi::addon::CheckSettingBoolean("onlycloud", m_onlycloud))
  {
    /* If setting is unknown fallback to defaults */
    kodi::Log(ADDON_LOG_ERROR, "Couldn't get 'onlycloud' setting");
    return false;
  }

  if (!kodi::addon::CheckSettingBoolean("deactivatehidden", m_deactivatehidden))
  {
    /* If setting is unknown fallback to defaults */
    kodi::Log(ADDON_LOG_ERROR, "Couldn't get 'deactivatehidden' setting");
    return false;
  }

  if (!kodi::addon::CheckSettingBoolean("higherresolution", m_higherresolution))
  {
    /* If setting is unknown fallback to defaults */
    kodi::Log(ADDON_LOG_ERROR, "Couldn't get 'higherresolution' setting");
    return false;
  }

  if (!kodi::addon::CheckSettingBoolean("enablegroups", m_enablegroups))
  {
    /* If setting is unknown fallback to defaults */
    kodi::Log(ADDON_LOG_ERROR, "Couldn't get 'enablegroups' setting");
    return false;
  }

  if (!kodi::addon::CheckSettingBoolean("ismagentatwo", m_ismagenta2))
  {
    /* If setting is unknown fallback to defaults */
    kodi::Log(ADDON_LOG_ERROR, "Couldn't get 'ismagentatwo' setting");
    return false;
  }

  if (!kodi::addon::CheckSettingBoolean("isonlyfavorites", m_onlyfavorites))
  {
    /* If setting is unknown fallback to defaults */
    kodi::Log(ADDON_LOG_ERROR, "Couldn't get 'isonlyfavorites' setting");
    return false;
  }

  if (!kodi::addon::CheckSettingInt("terminaltype", m_terminaltype))
  {
    /* If setting is unknown fallback to defaults */
    kodi::Log(ADDON_LOG_ERROR, "Couldn't get 'terminaltype' setting");
    return false;
  }

  if (!kodi::addon::CheckSettingInt("deletemode", m_deletemode))
  {
    /* If setting is unknown fallback to defaults */
    kodi::Log(ADDON_LOG_ERROR, "Couldn't get 'deletemode' setting");
    return false;
  }

  if (!kodi::addon::CheckSettingInt("deletemodeseries", m_deletemodeseries))
  {
    /* If setting is unknown fallback to defaults */
    kodi::Log(ADDON_LOG_ERROR, "Couldn't get 'deletemodeseries' setting");
    return false;
  }

  return true;
}

ADDON_STATUS CSettings::SetSetting(const std::string& settingName,
                                   const std::string& settingValue)
{
  if (settingName == "epg_token")
  {
    std::string tmp_sToken;
    kodi::Log(ADDON_LOG_DEBUG, "Changed Setting 'epg_token'");
    tmp_sToken = m_epgToken;
    m_epgToken = settingValue;
    if (tmp_sToken != m_epgToken)
    {
      kodi::addon::SetSettingString("epg_token", m_epgToken);
  //      return ADDON_STATUS_NEED_RESTART;
    }
  }
  else if (settingName == "openid_token")
  {
    std::string tmp_oToken;
    kodi::Log(ADDON_LOG_DEBUG, "Changed Setting 'openid_token'");
    tmp_oToken = m_openidToken;
    m_openidToken = settingValue;
    if (tmp_oToken != m_openidToken)
    {
      kodi::addon::SetSettingString("openid_token", m_openidToken);
  //      return ADDON_STATUS_NEED_RESTART;
    }
  }
  else if (settingName == "tv_token")
  {
    std::string tmp_tToken;
    kodi::Log(ADDON_LOG_DEBUG, "Changed Setting 'tv_token'");
    tmp_tToken = m_tvToken;
    m_tvToken = settingValue;
    if (tmp_tToken != m_tvToken)
    {
      kodi::addon::SetSettingString("tv_token", m_tvToken);
  //      return ADDON_STATUS_NEED_RESTART;
    }
  }
  else if (settingName == "refresh_token")
  {
    std::string tmp_rToken;
    kodi::Log(ADDON_LOG_DEBUG, "Changed Setting 'refresh_token'");
    tmp_rToken = m_refreshToken;
    m_refreshToken = settingValue;
    if (tmp_rToken != m_refreshToken)
    {
      kodi::addon::SetSettingString("refresh_token", m_refreshToken);
  //      return ADDON_STATUS_NEED_RESTART;
    }
  }
  else if (settingName == "csrftoken")
  {
    std::string tmp_cToken;
    kodi::Log(ADDON_LOG_DEBUG, "Changed Setting 'csrftoken'");
    tmp_cToken = m_csrfToken;
    m_csrfToken = settingValue;
    if (tmp_cToken != m_csrfToken)
    {
      kodi::addon::SetSettingString("csrftoken", m_csrfToken);
  //      return ADDON_STATUS_NEED_RESTART;
    }
  }
  else if (settingName == "personaltoken")
  {
    std::string tmp_pToken;
    kodi::Log(ADDON_LOG_DEBUG, "Changed Setting 'personaltoken'");
    tmp_pToken = m_personalToken;
    m_personalToken = settingValue;
    if (tmp_pToken != m_personalToken)
    {
      kodi::addon::SetSettingString("personaltoken", m_personalToken);
  //      return ADDON_STATUS_NEED_RESTART;
    }
  }
  else if (settingName == "deviceid")
  {
    std::string tmp_sDeviceID;
    kodi::Log(ADDON_LOG_DEBUG, "Changed Setting 'deviceid'");
    tmp_sDeviceID = m_magentaDeviceID;
    m_magentaDeviceID = settingValue;
    if (tmp_sDeviceID != m_magentaDeviceID)
    {
      kodi::addon::SetSettingString("deviceid", m_magentaDeviceID);
    //      return ADDON_STATUS_NEED_RESTART;
    }
  }

  return ADDON_STATUS_OK;
}

bool CSettings::VerifySettings() {
/*
  std::string username = GetMagentaUsername();
  std::string password = GetMagentaPassword();
  if (username.empty() || password.empty()) {
    kodi::Log(ADDON_LOG_INFO, "Username or password not set.");
    kodi::QueueNotification(QUEUE_WARNING, "", kodi::addon::GetLocalizedString(30200));

    return false;
  }
*/
  return true;
}
