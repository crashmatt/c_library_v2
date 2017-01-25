#pragma once
// MESSAGE MIXER_DATA PACKING

#define MAVLINK_MSG_ID_MIXER_DATA 270

MAVPACKED(
typedef struct __mavlink_mixer_data_t {
 float param_value; /*< Parameter or mixer data value*/
 uint8_t target_system; /*< system ID of the target*/
 uint8_t target_component; /*< component ID of the target*/
 uint8_t mixer_group; /*< Access to different sets of mixers ie. onboard, failsafe, uavcan etc..*/
 uint8_t mixer_index; /*< Index of the mixer in the group*/
 uint8_t mixer_sub_index; /*< Index of the sub mixer in the mixer*/
 uint8_t parameter_index; /*< Index of the parameter in the mixer or sub mixer*/
 uint8_t data_type; /*< Mixer data type*/
 uint8_t param_type; /*< Parameter type: see the MAV_PARAM_TYPE enum for supported data types.*/
}) mavlink_mixer_data_t;

#define MAVLINK_MSG_ID_MIXER_DATA_LEN 12
#define MAVLINK_MSG_ID_MIXER_DATA_MIN_LEN 12
#define MAVLINK_MSG_ID_270_LEN 12
#define MAVLINK_MSG_ID_270_MIN_LEN 12

#define MAVLINK_MSG_ID_MIXER_DATA_CRC 169
#define MAVLINK_MSG_ID_270_CRC 169



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_MIXER_DATA { \
	270, \
	"MIXER_DATA", \
	9, \
	{  { "param_value", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_mixer_data_t, param_value) }, \
         { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_mixer_data_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_mixer_data_t, target_component) }, \
         { "mixer_group", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_mixer_data_t, mixer_group) }, \
         { "mixer_index", NULL, MAVLINK_TYPE_UINT8_T, 0, 7, offsetof(mavlink_mixer_data_t, mixer_index) }, \
         { "mixer_sub_index", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_mixer_data_t, mixer_sub_index) }, \
         { "parameter_index", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_mixer_data_t, parameter_index) }, \
         { "data_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 10, offsetof(mavlink_mixer_data_t, data_type) }, \
         { "param_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 11, offsetof(mavlink_mixer_data_t, param_type) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_MIXER_DATA { \
	"MIXER_DATA", \
	9, \
	{  { "param_value", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_mixer_data_t, param_value) }, \
         { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_mixer_data_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_mixer_data_t, target_component) }, \
         { "mixer_group", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_mixer_data_t, mixer_group) }, \
         { "mixer_index", NULL, MAVLINK_TYPE_UINT8_T, 0, 7, offsetof(mavlink_mixer_data_t, mixer_index) }, \
         { "mixer_sub_index", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_mixer_data_t, mixer_sub_index) }, \
         { "parameter_index", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_mixer_data_t, parameter_index) }, \
         { "data_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 10, offsetof(mavlink_mixer_data_t, data_type) }, \
         { "param_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 11, offsetof(mavlink_mixer_data_t, param_type) }, \
         } \
}
#endif

/**
 * @brief Pack a mixer_data message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system system ID of the target
 * @param target_component component ID of the target
 * @param mixer_group Access to different sets of mixers ie. onboard, failsafe, uavcan etc..
 * @param mixer_index Index of the mixer in the group
 * @param mixer_sub_index Index of the sub mixer in the mixer
 * @param parameter_index Index of the parameter in the mixer or sub mixer
 * @param data_type Mixer data type
 * @param param_value Parameter or mixer data value
 * @param param_type Parameter type: see the MAV_PARAM_TYPE enum for supported data types.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_mixer_data_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t target_system, uint8_t target_component, uint8_t mixer_group, uint8_t mixer_index, uint8_t mixer_sub_index, uint8_t parameter_index, uint8_t data_type, float param_value, uint8_t param_type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_MIXER_DATA_LEN];
	_mav_put_float(buf, 0, param_value);
	_mav_put_uint8_t(buf, 4, target_system);
	_mav_put_uint8_t(buf, 5, target_component);
	_mav_put_uint8_t(buf, 6, mixer_group);
	_mav_put_uint8_t(buf, 7, mixer_index);
	_mav_put_uint8_t(buf, 8, mixer_sub_index);
	_mav_put_uint8_t(buf, 9, parameter_index);
	_mav_put_uint8_t(buf, 10, data_type);
	_mav_put_uint8_t(buf, 11, param_type);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MIXER_DATA_LEN);
#else
	mavlink_mixer_data_t packet;
	packet.param_value = param_value;
	packet.target_system = target_system;
	packet.target_component = target_component;
	packet.mixer_group = mixer_group;
	packet.mixer_index = mixer_index;
	packet.mixer_sub_index = mixer_sub_index;
	packet.parameter_index = parameter_index;
	packet.data_type = data_type;
	packet.param_type = param_type;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MIXER_DATA_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_MIXER_DATA;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_MIXER_DATA_MIN_LEN, MAVLINK_MSG_ID_MIXER_DATA_LEN, MAVLINK_MSG_ID_MIXER_DATA_CRC);
}

/**
 * @brief Pack a mixer_data message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system system ID of the target
 * @param target_component component ID of the target
 * @param mixer_group Access to different sets of mixers ie. onboard, failsafe, uavcan etc..
 * @param mixer_index Index of the mixer in the group
 * @param mixer_sub_index Index of the sub mixer in the mixer
 * @param parameter_index Index of the parameter in the mixer or sub mixer
 * @param data_type Mixer data type
 * @param param_value Parameter or mixer data value
 * @param param_type Parameter type: see the MAV_PARAM_TYPE enum for supported data types.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_mixer_data_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t target_system,uint8_t target_component,uint8_t mixer_group,uint8_t mixer_index,uint8_t mixer_sub_index,uint8_t parameter_index,uint8_t data_type,float param_value,uint8_t param_type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_MIXER_DATA_LEN];
	_mav_put_float(buf, 0, param_value);
	_mav_put_uint8_t(buf, 4, target_system);
	_mav_put_uint8_t(buf, 5, target_component);
	_mav_put_uint8_t(buf, 6, mixer_group);
	_mav_put_uint8_t(buf, 7, mixer_index);
	_mav_put_uint8_t(buf, 8, mixer_sub_index);
	_mav_put_uint8_t(buf, 9, parameter_index);
	_mav_put_uint8_t(buf, 10, data_type);
	_mav_put_uint8_t(buf, 11, param_type);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MIXER_DATA_LEN);
#else
	mavlink_mixer_data_t packet;
	packet.param_value = param_value;
	packet.target_system = target_system;
	packet.target_component = target_component;
	packet.mixer_group = mixer_group;
	packet.mixer_index = mixer_index;
	packet.mixer_sub_index = mixer_sub_index;
	packet.parameter_index = parameter_index;
	packet.data_type = data_type;
	packet.param_type = param_type;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MIXER_DATA_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_MIXER_DATA;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_MIXER_DATA_MIN_LEN, MAVLINK_MSG_ID_MIXER_DATA_LEN, MAVLINK_MSG_ID_MIXER_DATA_CRC);
}

/**
 * @brief Encode a mixer_data struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param mixer_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_mixer_data_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_mixer_data_t* mixer_data)
{
	return mavlink_msg_mixer_data_pack(system_id, component_id, msg, mixer_data->target_system, mixer_data->target_component, mixer_data->mixer_group, mixer_data->mixer_index, mixer_data->mixer_sub_index, mixer_data->parameter_index, mixer_data->data_type, mixer_data->param_value, mixer_data->param_type);
}

/**
 * @brief Encode a mixer_data struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param mixer_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_mixer_data_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_mixer_data_t* mixer_data)
{
	return mavlink_msg_mixer_data_pack_chan(system_id, component_id, chan, msg, mixer_data->target_system, mixer_data->target_component, mixer_data->mixer_group, mixer_data->mixer_index, mixer_data->mixer_sub_index, mixer_data->parameter_index, mixer_data->data_type, mixer_data->param_value, mixer_data->param_type);
}

/**
 * @brief Send a mixer_data message
 * @param chan MAVLink channel to send the message
 *
 * @param target_system system ID of the target
 * @param target_component component ID of the target
 * @param mixer_group Access to different sets of mixers ie. onboard, failsafe, uavcan etc..
 * @param mixer_index Index of the mixer in the group
 * @param mixer_sub_index Index of the sub mixer in the mixer
 * @param parameter_index Index of the parameter in the mixer or sub mixer
 * @param data_type Mixer data type
 * @param param_value Parameter or mixer data value
 * @param param_type Parameter type: see the MAV_PARAM_TYPE enum for supported data types.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_mixer_data_send(mavlink_channel_t chan, uint8_t target_system, uint8_t target_component, uint8_t mixer_group, uint8_t mixer_index, uint8_t mixer_sub_index, uint8_t parameter_index, uint8_t data_type, float param_value, uint8_t param_type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_MIXER_DATA_LEN];
	_mav_put_float(buf, 0, param_value);
	_mav_put_uint8_t(buf, 4, target_system);
	_mav_put_uint8_t(buf, 5, target_component);
	_mav_put_uint8_t(buf, 6, mixer_group);
	_mav_put_uint8_t(buf, 7, mixer_index);
	_mav_put_uint8_t(buf, 8, mixer_sub_index);
	_mav_put_uint8_t(buf, 9, parameter_index);
	_mav_put_uint8_t(buf, 10, data_type);
	_mav_put_uint8_t(buf, 11, param_type);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MIXER_DATA, buf, MAVLINK_MSG_ID_MIXER_DATA_MIN_LEN, MAVLINK_MSG_ID_MIXER_DATA_LEN, MAVLINK_MSG_ID_MIXER_DATA_CRC);
#else
	mavlink_mixer_data_t packet;
	packet.param_value = param_value;
	packet.target_system = target_system;
	packet.target_component = target_component;
	packet.mixer_group = mixer_group;
	packet.mixer_index = mixer_index;
	packet.mixer_sub_index = mixer_sub_index;
	packet.parameter_index = parameter_index;
	packet.data_type = data_type;
	packet.param_type = param_type;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MIXER_DATA, (const char *)&packet, MAVLINK_MSG_ID_MIXER_DATA_MIN_LEN, MAVLINK_MSG_ID_MIXER_DATA_LEN, MAVLINK_MSG_ID_MIXER_DATA_CRC);
#endif
}

/**
 * @brief Send a mixer_data message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_mixer_data_send_struct(mavlink_channel_t chan, const mavlink_mixer_data_t* mixer_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_mixer_data_send(chan, mixer_data->target_system, mixer_data->target_component, mixer_data->mixer_group, mixer_data->mixer_index, mixer_data->mixer_sub_index, mixer_data->parameter_index, mixer_data->data_type, mixer_data->param_value, mixer_data->param_type);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MIXER_DATA, (const char *)mixer_data, MAVLINK_MSG_ID_MIXER_DATA_MIN_LEN, MAVLINK_MSG_ID_MIXER_DATA_LEN, MAVLINK_MSG_ID_MIXER_DATA_CRC);
#endif
}

#if MAVLINK_MSG_ID_MIXER_DATA_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_mixer_data_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t target_system, uint8_t target_component, uint8_t mixer_group, uint8_t mixer_index, uint8_t mixer_sub_index, uint8_t parameter_index, uint8_t data_type, float param_value, uint8_t param_type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_float(buf, 0, param_value);
	_mav_put_uint8_t(buf, 4, target_system);
	_mav_put_uint8_t(buf, 5, target_component);
	_mav_put_uint8_t(buf, 6, mixer_group);
	_mav_put_uint8_t(buf, 7, mixer_index);
	_mav_put_uint8_t(buf, 8, mixer_sub_index);
	_mav_put_uint8_t(buf, 9, parameter_index);
	_mav_put_uint8_t(buf, 10, data_type);
	_mav_put_uint8_t(buf, 11, param_type);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MIXER_DATA, buf, MAVLINK_MSG_ID_MIXER_DATA_MIN_LEN, MAVLINK_MSG_ID_MIXER_DATA_LEN, MAVLINK_MSG_ID_MIXER_DATA_CRC);
#else
	mavlink_mixer_data_t *packet = (mavlink_mixer_data_t *)msgbuf;
	packet->param_value = param_value;
	packet->target_system = target_system;
	packet->target_component = target_component;
	packet->mixer_group = mixer_group;
	packet->mixer_index = mixer_index;
	packet->mixer_sub_index = mixer_sub_index;
	packet->parameter_index = parameter_index;
	packet->data_type = data_type;
	packet->param_type = param_type;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MIXER_DATA, (const char *)packet, MAVLINK_MSG_ID_MIXER_DATA_MIN_LEN, MAVLINK_MSG_ID_MIXER_DATA_LEN, MAVLINK_MSG_ID_MIXER_DATA_CRC);
#endif
}
#endif

#endif

// MESSAGE MIXER_DATA UNPACKING


/**
 * @brief Get field target_system from mixer_data message
 *
 * @return system ID of the target
 */
static inline uint8_t mavlink_msg_mixer_data_get_target_system(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  4);
}

/**
 * @brief Get field target_component from mixer_data message
 *
 * @return component ID of the target
 */
static inline uint8_t mavlink_msg_mixer_data_get_target_component(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  5);
}

/**
 * @brief Get field mixer_group from mixer_data message
 *
 * @return Access to different sets of mixers ie. onboard, failsafe, uavcan etc..
 */
static inline uint8_t mavlink_msg_mixer_data_get_mixer_group(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  6);
}

/**
 * @brief Get field mixer_index from mixer_data message
 *
 * @return Index of the mixer in the group
 */
static inline uint8_t mavlink_msg_mixer_data_get_mixer_index(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  7);
}

/**
 * @brief Get field mixer_sub_index from mixer_data message
 *
 * @return Index of the sub mixer in the mixer
 */
static inline uint8_t mavlink_msg_mixer_data_get_mixer_sub_index(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  8);
}

/**
 * @brief Get field parameter_index from mixer_data message
 *
 * @return Index of the parameter in the mixer or sub mixer
 */
static inline uint8_t mavlink_msg_mixer_data_get_parameter_index(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  9);
}

/**
 * @brief Get field data_type from mixer_data message
 *
 * @return Mixer data type
 */
static inline uint8_t mavlink_msg_mixer_data_get_data_type(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  10);
}

/**
 * @brief Get field param_value from mixer_data message
 *
 * @return Parameter or mixer data value
 */
static inline float mavlink_msg_mixer_data_get_param_value(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field param_type from mixer_data message
 *
 * @return Parameter type: see the MAV_PARAM_TYPE enum for supported data types.
 */
static inline uint8_t mavlink_msg_mixer_data_get_param_type(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  11);
}

/**
 * @brief Decode a mixer_data message into a struct
 *
 * @param msg The message to decode
 * @param mixer_data C-struct to decode the message contents into
 */
static inline void mavlink_msg_mixer_data_decode(const mavlink_message_t* msg, mavlink_mixer_data_t* mixer_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	mixer_data->param_value = mavlink_msg_mixer_data_get_param_value(msg);
	mixer_data->target_system = mavlink_msg_mixer_data_get_target_system(msg);
	mixer_data->target_component = mavlink_msg_mixer_data_get_target_component(msg);
	mixer_data->mixer_group = mavlink_msg_mixer_data_get_mixer_group(msg);
	mixer_data->mixer_index = mavlink_msg_mixer_data_get_mixer_index(msg);
	mixer_data->mixer_sub_index = mavlink_msg_mixer_data_get_mixer_sub_index(msg);
	mixer_data->parameter_index = mavlink_msg_mixer_data_get_parameter_index(msg);
	mixer_data->data_type = mavlink_msg_mixer_data_get_data_type(msg);
	mixer_data->param_type = mavlink_msg_mixer_data_get_param_type(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_MIXER_DATA_LEN? msg->len : MAVLINK_MSG_ID_MIXER_DATA_LEN;
        memset(mixer_data, 0, MAVLINK_MSG_ID_MIXER_DATA_LEN);
	memcpy(mixer_data, _MAV_PAYLOAD(msg), len);
#endif
}
