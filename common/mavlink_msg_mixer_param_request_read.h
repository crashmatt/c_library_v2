#pragma once
// MESSAGE MIXER_PARAM_REQUEST_READ PACKING

#define MAVLINK_MSG_ID_MIXER_PARAM_REQUEST_READ 237

MAVPACKED(
typedef struct __mavlink_mixer_param_request_read_t {
 uint16_t index; /*< Index of this onboard parameter*/
 uint16_t mixer_index; /*< Index of the mixer in the group*/
 uint16_t parameter_index; /*< Index of the parameter in a mixer or something else*/
 uint8_t target_system; /*< System ID*/
 uint8_t target_component; /*< Component ID*/
 uint8_t mixer_group; /*< Access to different sets of mixers*/
 uint8_t mixer_sub_index; /*< Index of the sub mixer in the mixer*/
 uint8_t param_type; /*< Parameter type: see the MAV_PARAM_TYPE enum for supported data types.*/
 char param_id[16]; /*< Onboard parameter id, terminated by NULL if the length is less than 16 human-readable chars and WITHOUT null termination (NULL) byte if the length is exactly 16 chars - applications have to provide 16+1 bytes storage if the ID is stored as string*/
}) mavlink_mixer_param_request_read_t;

#define MAVLINK_MSG_ID_MIXER_PARAM_REQUEST_READ_LEN 27
#define MAVLINK_MSG_ID_MIXER_PARAM_REQUEST_READ_MIN_LEN 27
#define MAVLINK_MSG_ID_237_LEN 27
#define MAVLINK_MSG_ID_237_MIN_LEN 27

#define MAVLINK_MSG_ID_MIXER_PARAM_REQUEST_READ_CRC 195
#define MAVLINK_MSG_ID_237_CRC 195

#define MAVLINK_MSG_MIXER_PARAM_REQUEST_READ_FIELD_PARAM_ID_LEN 16

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_MIXER_PARAM_REQUEST_READ { \
    237, \
    "MIXER_PARAM_REQUEST_READ", \
    9, \
    {  { "index", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_mixer_param_request_read_t, index) }, \
         { "mixer_index", NULL, MAVLINK_TYPE_UINT16_T, 0, 2, offsetof(mavlink_mixer_param_request_read_t, mixer_index) }, \
         { "parameter_index", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_mixer_param_request_read_t, parameter_index) }, \
         { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_mixer_param_request_read_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 7, offsetof(mavlink_mixer_param_request_read_t, target_component) }, \
         { "mixer_group", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_mixer_param_request_read_t, mixer_group) }, \
         { "mixer_sub_index", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_mixer_param_request_read_t, mixer_sub_index) }, \
         { "param_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 10, offsetof(mavlink_mixer_param_request_read_t, param_type) }, \
         { "param_id", NULL, MAVLINK_TYPE_CHAR, 16, 11, offsetof(mavlink_mixer_param_request_read_t, param_id) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_MIXER_PARAM_REQUEST_READ { \
    "MIXER_PARAM_REQUEST_READ", \
    9, \
    {  { "index", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_mixer_param_request_read_t, index) }, \
         { "mixer_index", NULL, MAVLINK_TYPE_UINT16_T, 0, 2, offsetof(mavlink_mixer_param_request_read_t, mixer_index) }, \
         { "parameter_index", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_mixer_param_request_read_t, parameter_index) }, \
         { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_mixer_param_request_read_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 7, offsetof(mavlink_mixer_param_request_read_t, target_component) }, \
         { "mixer_group", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_mixer_param_request_read_t, mixer_group) }, \
         { "mixer_sub_index", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_mixer_param_request_read_t, mixer_sub_index) }, \
         { "param_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 10, offsetof(mavlink_mixer_param_request_read_t, param_type) }, \
         { "param_id", NULL, MAVLINK_TYPE_CHAR, 16, 11, offsetof(mavlink_mixer_param_request_read_t, param_id) }, \
         } \
}
#endif

/**
 * @brief Pack a mixer_param_request_read message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system System ID
 * @param target_component Component ID
 * @param index Index of this onboard parameter
 * @param mixer_group Access to different sets of mixers
 * @param mixer_index Index of the mixer in the group
 * @param mixer_sub_index Index of the sub mixer in the mixer
 * @param parameter_index Index of the parameter in a mixer or something else
 * @param param_type Parameter type: see the MAV_PARAM_TYPE enum for supported data types.
 * @param param_id Onboard parameter id, terminated by NULL if the length is less than 16 human-readable chars and WITHOUT null termination (NULL) byte if the length is exactly 16 chars - applications have to provide 16+1 bytes storage if the ID is stored as string
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_mixer_param_request_read_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t target_system, uint8_t target_component, uint16_t index, uint8_t mixer_group, uint16_t mixer_index, uint8_t mixer_sub_index, uint16_t parameter_index, uint8_t param_type, const char *param_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MIXER_PARAM_REQUEST_READ_LEN];
    _mav_put_uint16_t(buf, 0, index);
    _mav_put_uint16_t(buf, 2, mixer_index);
    _mav_put_uint16_t(buf, 4, parameter_index);
    _mav_put_uint8_t(buf, 6, target_system);
    _mav_put_uint8_t(buf, 7, target_component);
    _mav_put_uint8_t(buf, 8, mixer_group);
    _mav_put_uint8_t(buf, 9, mixer_sub_index);
    _mav_put_uint8_t(buf, 10, param_type);
    _mav_put_char_array(buf, 11, param_id, 16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MIXER_PARAM_REQUEST_READ_LEN);
#else
    mavlink_mixer_param_request_read_t packet;
    packet.index = index;
    packet.mixer_index = mixer_index;
    packet.parameter_index = parameter_index;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.mixer_group = mixer_group;
    packet.mixer_sub_index = mixer_sub_index;
    packet.param_type = param_type;
    mav_array_memcpy(packet.param_id, param_id, sizeof(char)*16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MIXER_PARAM_REQUEST_READ_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MIXER_PARAM_REQUEST_READ;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_MIXER_PARAM_REQUEST_READ_MIN_LEN, MAVLINK_MSG_ID_MIXER_PARAM_REQUEST_READ_LEN, MAVLINK_MSG_ID_MIXER_PARAM_REQUEST_READ_CRC);
}

/**
 * @brief Pack a mixer_param_request_read message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system System ID
 * @param target_component Component ID
 * @param index Index of this onboard parameter
 * @param mixer_group Access to different sets of mixers
 * @param mixer_index Index of the mixer in the group
 * @param mixer_sub_index Index of the sub mixer in the mixer
 * @param parameter_index Index of the parameter in a mixer or something else
 * @param param_type Parameter type: see the MAV_PARAM_TYPE enum for supported data types.
 * @param param_id Onboard parameter id, terminated by NULL if the length is less than 16 human-readable chars and WITHOUT null termination (NULL) byte if the length is exactly 16 chars - applications have to provide 16+1 bytes storage if the ID is stored as string
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_mixer_param_request_read_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t target_system,uint8_t target_component,uint16_t index,uint8_t mixer_group,uint16_t mixer_index,uint8_t mixer_sub_index,uint16_t parameter_index,uint8_t param_type,const char *param_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MIXER_PARAM_REQUEST_READ_LEN];
    _mav_put_uint16_t(buf, 0, index);
    _mav_put_uint16_t(buf, 2, mixer_index);
    _mav_put_uint16_t(buf, 4, parameter_index);
    _mav_put_uint8_t(buf, 6, target_system);
    _mav_put_uint8_t(buf, 7, target_component);
    _mav_put_uint8_t(buf, 8, mixer_group);
    _mav_put_uint8_t(buf, 9, mixer_sub_index);
    _mav_put_uint8_t(buf, 10, param_type);
    _mav_put_char_array(buf, 11, param_id, 16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MIXER_PARAM_REQUEST_READ_LEN);
#else
    mavlink_mixer_param_request_read_t packet;
    packet.index = index;
    packet.mixer_index = mixer_index;
    packet.parameter_index = parameter_index;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.mixer_group = mixer_group;
    packet.mixer_sub_index = mixer_sub_index;
    packet.param_type = param_type;
    mav_array_memcpy(packet.param_id, param_id, sizeof(char)*16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MIXER_PARAM_REQUEST_READ_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MIXER_PARAM_REQUEST_READ;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_MIXER_PARAM_REQUEST_READ_MIN_LEN, MAVLINK_MSG_ID_MIXER_PARAM_REQUEST_READ_LEN, MAVLINK_MSG_ID_MIXER_PARAM_REQUEST_READ_CRC);
}

/**
 * @brief Encode a mixer_param_request_read struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param mixer_param_request_read C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_mixer_param_request_read_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_mixer_param_request_read_t* mixer_param_request_read)
{
    return mavlink_msg_mixer_param_request_read_pack(system_id, component_id, msg, mixer_param_request_read->target_system, mixer_param_request_read->target_component, mixer_param_request_read->index, mixer_param_request_read->mixer_group, mixer_param_request_read->mixer_index, mixer_param_request_read->mixer_sub_index, mixer_param_request_read->parameter_index, mixer_param_request_read->param_type, mixer_param_request_read->param_id);
}

/**
 * @brief Encode a mixer_param_request_read struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param mixer_param_request_read C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_mixer_param_request_read_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_mixer_param_request_read_t* mixer_param_request_read)
{
    return mavlink_msg_mixer_param_request_read_pack_chan(system_id, component_id, chan, msg, mixer_param_request_read->target_system, mixer_param_request_read->target_component, mixer_param_request_read->index, mixer_param_request_read->mixer_group, mixer_param_request_read->mixer_index, mixer_param_request_read->mixer_sub_index, mixer_param_request_read->parameter_index, mixer_param_request_read->param_type, mixer_param_request_read->param_id);
}

/**
 * @brief Send a mixer_param_request_read message
 * @param chan MAVLink channel to send the message
 *
 * @param target_system System ID
 * @param target_component Component ID
 * @param index Index of this onboard parameter
 * @param mixer_group Access to different sets of mixers
 * @param mixer_index Index of the mixer in the group
 * @param mixer_sub_index Index of the sub mixer in the mixer
 * @param parameter_index Index of the parameter in a mixer or something else
 * @param param_type Parameter type: see the MAV_PARAM_TYPE enum for supported data types.
 * @param param_id Onboard parameter id, terminated by NULL if the length is less than 16 human-readable chars and WITHOUT null termination (NULL) byte if the length is exactly 16 chars - applications have to provide 16+1 bytes storage if the ID is stored as string
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_mixer_param_request_read_send(mavlink_channel_t chan, uint8_t target_system, uint8_t target_component, uint16_t index, uint8_t mixer_group, uint16_t mixer_index, uint8_t mixer_sub_index, uint16_t parameter_index, uint8_t param_type, const char *param_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MIXER_PARAM_REQUEST_READ_LEN];
    _mav_put_uint16_t(buf, 0, index);
    _mav_put_uint16_t(buf, 2, mixer_index);
    _mav_put_uint16_t(buf, 4, parameter_index);
    _mav_put_uint8_t(buf, 6, target_system);
    _mav_put_uint8_t(buf, 7, target_component);
    _mav_put_uint8_t(buf, 8, mixer_group);
    _mav_put_uint8_t(buf, 9, mixer_sub_index);
    _mav_put_uint8_t(buf, 10, param_type);
    _mav_put_char_array(buf, 11, param_id, 16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MIXER_PARAM_REQUEST_READ, buf, MAVLINK_MSG_ID_MIXER_PARAM_REQUEST_READ_MIN_LEN, MAVLINK_MSG_ID_MIXER_PARAM_REQUEST_READ_LEN, MAVLINK_MSG_ID_MIXER_PARAM_REQUEST_READ_CRC);
#else
    mavlink_mixer_param_request_read_t packet;
    packet.index = index;
    packet.mixer_index = mixer_index;
    packet.parameter_index = parameter_index;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.mixer_group = mixer_group;
    packet.mixer_sub_index = mixer_sub_index;
    packet.param_type = param_type;
    mav_array_memcpy(packet.param_id, param_id, sizeof(char)*16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MIXER_PARAM_REQUEST_READ, (const char *)&packet, MAVLINK_MSG_ID_MIXER_PARAM_REQUEST_READ_MIN_LEN, MAVLINK_MSG_ID_MIXER_PARAM_REQUEST_READ_LEN, MAVLINK_MSG_ID_MIXER_PARAM_REQUEST_READ_CRC);
#endif
}

/**
 * @brief Send a mixer_param_request_read message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_mixer_param_request_read_send_struct(mavlink_channel_t chan, const mavlink_mixer_param_request_read_t* mixer_param_request_read)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_mixer_param_request_read_send(chan, mixer_param_request_read->target_system, mixer_param_request_read->target_component, mixer_param_request_read->index, mixer_param_request_read->mixer_group, mixer_param_request_read->mixer_index, mixer_param_request_read->mixer_sub_index, mixer_param_request_read->parameter_index, mixer_param_request_read->param_type, mixer_param_request_read->param_id);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MIXER_PARAM_REQUEST_READ, (const char *)mixer_param_request_read, MAVLINK_MSG_ID_MIXER_PARAM_REQUEST_READ_MIN_LEN, MAVLINK_MSG_ID_MIXER_PARAM_REQUEST_READ_LEN, MAVLINK_MSG_ID_MIXER_PARAM_REQUEST_READ_CRC);
#endif
}

#if MAVLINK_MSG_ID_MIXER_PARAM_REQUEST_READ_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_mixer_param_request_read_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t target_system, uint8_t target_component, uint16_t index, uint8_t mixer_group, uint16_t mixer_index, uint8_t mixer_sub_index, uint16_t parameter_index, uint8_t param_type, const char *param_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint16_t(buf, 0, index);
    _mav_put_uint16_t(buf, 2, mixer_index);
    _mav_put_uint16_t(buf, 4, parameter_index);
    _mav_put_uint8_t(buf, 6, target_system);
    _mav_put_uint8_t(buf, 7, target_component);
    _mav_put_uint8_t(buf, 8, mixer_group);
    _mav_put_uint8_t(buf, 9, mixer_sub_index);
    _mav_put_uint8_t(buf, 10, param_type);
    _mav_put_char_array(buf, 11, param_id, 16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MIXER_PARAM_REQUEST_READ, buf, MAVLINK_MSG_ID_MIXER_PARAM_REQUEST_READ_MIN_LEN, MAVLINK_MSG_ID_MIXER_PARAM_REQUEST_READ_LEN, MAVLINK_MSG_ID_MIXER_PARAM_REQUEST_READ_CRC);
#else
    mavlink_mixer_param_request_read_t *packet = (mavlink_mixer_param_request_read_t *)msgbuf;
    packet->index = index;
    packet->mixer_index = mixer_index;
    packet->parameter_index = parameter_index;
    packet->target_system = target_system;
    packet->target_component = target_component;
    packet->mixer_group = mixer_group;
    packet->mixer_sub_index = mixer_sub_index;
    packet->param_type = param_type;
    mav_array_memcpy(packet->param_id, param_id, sizeof(char)*16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MIXER_PARAM_REQUEST_READ, (const char *)packet, MAVLINK_MSG_ID_MIXER_PARAM_REQUEST_READ_MIN_LEN, MAVLINK_MSG_ID_MIXER_PARAM_REQUEST_READ_LEN, MAVLINK_MSG_ID_MIXER_PARAM_REQUEST_READ_CRC);
#endif
}
#endif

#endif

// MESSAGE MIXER_PARAM_REQUEST_READ UNPACKING


/**
 * @brief Get field target_system from mixer_param_request_read message
 *
 * @return System ID
 */
static inline uint8_t mavlink_msg_mixer_param_request_read_get_target_system(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  6);
}

/**
 * @brief Get field target_component from mixer_param_request_read message
 *
 * @return Component ID
 */
static inline uint8_t mavlink_msg_mixer_param_request_read_get_target_component(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  7);
}

/**
 * @brief Get field index from mixer_param_request_read message
 *
 * @return Index of this onboard parameter
 */
static inline uint16_t mavlink_msg_mixer_param_request_read_get_index(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  0);
}

/**
 * @brief Get field mixer_group from mixer_param_request_read message
 *
 * @return Access to different sets of mixers
 */
static inline uint8_t mavlink_msg_mixer_param_request_read_get_mixer_group(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  8);
}

/**
 * @brief Get field mixer_index from mixer_param_request_read message
 *
 * @return Index of the mixer in the group
 */
static inline uint16_t mavlink_msg_mixer_param_request_read_get_mixer_index(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  2);
}

/**
 * @brief Get field mixer_sub_index from mixer_param_request_read message
 *
 * @return Index of the sub mixer in the mixer
 */
static inline uint8_t mavlink_msg_mixer_param_request_read_get_mixer_sub_index(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  9);
}

/**
 * @brief Get field parameter_index from mixer_param_request_read message
 *
 * @return Index of the parameter in a mixer or something else
 */
static inline uint16_t mavlink_msg_mixer_param_request_read_get_parameter_index(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  4);
}

/**
 * @brief Get field param_type from mixer_param_request_read message
 *
 * @return Parameter type: see the MAV_PARAM_TYPE enum for supported data types.
 */
static inline uint8_t mavlink_msg_mixer_param_request_read_get_param_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  10);
}

/**
 * @brief Get field param_id from mixer_param_request_read message
 *
 * @return Onboard parameter id, terminated by NULL if the length is less than 16 human-readable chars and WITHOUT null termination (NULL) byte if the length is exactly 16 chars - applications have to provide 16+1 bytes storage if the ID is stored as string
 */
static inline uint16_t mavlink_msg_mixer_param_request_read_get_param_id(const mavlink_message_t* msg, char *param_id)
{
    return _MAV_RETURN_char_array(msg, param_id, 16,  11);
}

/**
 * @brief Decode a mixer_param_request_read message into a struct
 *
 * @param msg The message to decode
 * @param mixer_param_request_read C-struct to decode the message contents into
 */
static inline void mavlink_msg_mixer_param_request_read_decode(const mavlink_message_t* msg, mavlink_mixer_param_request_read_t* mixer_param_request_read)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mixer_param_request_read->index = mavlink_msg_mixer_param_request_read_get_index(msg);
    mixer_param_request_read->mixer_index = mavlink_msg_mixer_param_request_read_get_mixer_index(msg);
    mixer_param_request_read->parameter_index = mavlink_msg_mixer_param_request_read_get_parameter_index(msg);
    mixer_param_request_read->target_system = mavlink_msg_mixer_param_request_read_get_target_system(msg);
    mixer_param_request_read->target_component = mavlink_msg_mixer_param_request_read_get_target_component(msg);
    mixer_param_request_read->mixer_group = mavlink_msg_mixer_param_request_read_get_mixer_group(msg);
    mixer_param_request_read->mixer_sub_index = mavlink_msg_mixer_param_request_read_get_mixer_sub_index(msg);
    mixer_param_request_read->param_type = mavlink_msg_mixer_param_request_read_get_param_type(msg);
    mavlink_msg_mixer_param_request_read_get_param_id(msg, mixer_param_request_read->param_id);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_MIXER_PARAM_REQUEST_READ_LEN? msg->len : MAVLINK_MSG_ID_MIXER_PARAM_REQUEST_READ_LEN;
        memset(mixer_param_request_read, 0, MAVLINK_MSG_ID_MIXER_PARAM_REQUEST_READ_LEN);
    memcpy(mixer_param_request_read, _MAV_PAYLOAD(msg), len);
#endif
}
