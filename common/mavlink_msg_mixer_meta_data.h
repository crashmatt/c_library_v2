#pragma once
// MESSAGE MIXER_META_DATA PACKING

#define MAVLINK_MSG_ID_MIXER_META_DATA 236

MAVPACKED(
typedef struct __mavlink_mixer_meta_data_t {
 uint16_t inputs[16]; /*< Mixer input connections*/
 uint16_t outputs[16]; /*< Mixer output connections*/
 uint8_t mixer_group; /*< Access to different sets of mixers ie. onboard, failsafe, uavcan etc..*/
 uint8_t mixer_index; /*< Index of the mixer in the group*/
 uint8_t mixer_sub_index; /*< Index of the sub mixer in the mixer*/
}) mavlink_mixer_meta_data_t;

#define MAVLINK_MSG_ID_MIXER_META_DATA_LEN 67
#define MAVLINK_MSG_ID_MIXER_META_DATA_MIN_LEN 67
#define MAVLINK_MSG_ID_236_LEN 67
#define MAVLINK_MSG_ID_236_MIN_LEN 67

#define MAVLINK_MSG_ID_MIXER_META_DATA_CRC 231
#define MAVLINK_MSG_ID_236_CRC 231

#define MAVLINK_MSG_MIXER_META_DATA_FIELD_INPUTS_LEN 16
#define MAVLINK_MSG_MIXER_META_DATA_FIELD_OUTPUTS_LEN 16

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_MIXER_META_DATA { \
    236, \
    "MIXER_META_DATA", \
    5, \
    {  { "inputs", NULL, MAVLINK_TYPE_UINT16_T, 16, 0, offsetof(mavlink_mixer_meta_data_t, inputs) }, \
         { "outputs", NULL, MAVLINK_TYPE_UINT16_T, 16, 32, offsetof(mavlink_mixer_meta_data_t, outputs) }, \
         { "mixer_group", NULL, MAVLINK_TYPE_UINT8_T, 0, 64, offsetof(mavlink_mixer_meta_data_t, mixer_group) }, \
         { "mixer_index", NULL, MAVLINK_TYPE_UINT8_T, 0, 65, offsetof(mavlink_mixer_meta_data_t, mixer_index) }, \
         { "mixer_sub_index", NULL, MAVLINK_TYPE_UINT8_T, 0, 66, offsetof(mavlink_mixer_meta_data_t, mixer_sub_index) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_MIXER_META_DATA { \
    "MIXER_META_DATA", \
    5, \
    {  { "inputs", NULL, MAVLINK_TYPE_UINT16_T, 16, 0, offsetof(mavlink_mixer_meta_data_t, inputs) }, \
         { "outputs", NULL, MAVLINK_TYPE_UINT16_T, 16, 32, offsetof(mavlink_mixer_meta_data_t, outputs) }, \
         { "mixer_group", NULL, MAVLINK_TYPE_UINT8_T, 0, 64, offsetof(mavlink_mixer_meta_data_t, mixer_group) }, \
         { "mixer_index", NULL, MAVLINK_TYPE_UINT8_T, 0, 65, offsetof(mavlink_mixer_meta_data_t, mixer_index) }, \
         { "mixer_sub_index", NULL, MAVLINK_TYPE_UINT8_T, 0, 66, offsetof(mavlink_mixer_meta_data_t, mixer_sub_index) }, \
         } \
}
#endif

/**
 * @brief Pack a mixer_meta_data message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param mixer_group Access to different sets of mixers ie. onboard, failsafe, uavcan etc..
 * @param mixer_index Index of the mixer in the group
 * @param mixer_sub_index Index of the sub mixer in the mixer
 * @param inputs Mixer input connections
 * @param outputs Mixer output connections
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_mixer_meta_data_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t mixer_group, uint8_t mixer_index, uint8_t mixer_sub_index, const uint16_t *inputs, const uint16_t *outputs)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MIXER_META_DATA_LEN];
    _mav_put_uint8_t(buf, 64, mixer_group);
    _mav_put_uint8_t(buf, 65, mixer_index);
    _mav_put_uint8_t(buf, 66, mixer_sub_index);
    _mav_put_uint16_t_array(buf, 0, inputs, 16);
    _mav_put_uint16_t_array(buf, 32, outputs, 16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MIXER_META_DATA_LEN);
#else
    mavlink_mixer_meta_data_t packet;
    packet.mixer_group = mixer_group;
    packet.mixer_index = mixer_index;
    packet.mixer_sub_index = mixer_sub_index;
    mav_array_memcpy(packet.inputs, inputs, sizeof(uint16_t)*16);
    mav_array_memcpy(packet.outputs, outputs, sizeof(uint16_t)*16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MIXER_META_DATA_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MIXER_META_DATA;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_MIXER_META_DATA_MIN_LEN, MAVLINK_MSG_ID_MIXER_META_DATA_LEN, MAVLINK_MSG_ID_MIXER_META_DATA_CRC);
}

/**
 * @brief Pack a mixer_meta_data message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param mixer_group Access to different sets of mixers ie. onboard, failsafe, uavcan etc..
 * @param mixer_index Index of the mixer in the group
 * @param mixer_sub_index Index of the sub mixer in the mixer
 * @param inputs Mixer input connections
 * @param outputs Mixer output connections
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_mixer_meta_data_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t mixer_group,uint8_t mixer_index,uint8_t mixer_sub_index,const uint16_t *inputs,const uint16_t *outputs)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MIXER_META_DATA_LEN];
    _mav_put_uint8_t(buf, 64, mixer_group);
    _mav_put_uint8_t(buf, 65, mixer_index);
    _mav_put_uint8_t(buf, 66, mixer_sub_index);
    _mav_put_uint16_t_array(buf, 0, inputs, 16);
    _mav_put_uint16_t_array(buf, 32, outputs, 16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MIXER_META_DATA_LEN);
#else
    mavlink_mixer_meta_data_t packet;
    packet.mixer_group = mixer_group;
    packet.mixer_index = mixer_index;
    packet.mixer_sub_index = mixer_sub_index;
    mav_array_memcpy(packet.inputs, inputs, sizeof(uint16_t)*16);
    mav_array_memcpy(packet.outputs, outputs, sizeof(uint16_t)*16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MIXER_META_DATA_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MIXER_META_DATA;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_MIXER_META_DATA_MIN_LEN, MAVLINK_MSG_ID_MIXER_META_DATA_LEN, MAVLINK_MSG_ID_MIXER_META_DATA_CRC);
}

/**
 * @brief Encode a mixer_meta_data struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param mixer_meta_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_mixer_meta_data_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_mixer_meta_data_t* mixer_meta_data)
{
    return mavlink_msg_mixer_meta_data_pack(system_id, component_id, msg, mixer_meta_data->mixer_group, mixer_meta_data->mixer_index, mixer_meta_data->mixer_sub_index, mixer_meta_data->inputs, mixer_meta_data->outputs);
}

/**
 * @brief Encode a mixer_meta_data struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param mixer_meta_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_mixer_meta_data_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_mixer_meta_data_t* mixer_meta_data)
{
    return mavlink_msg_mixer_meta_data_pack_chan(system_id, component_id, chan, msg, mixer_meta_data->mixer_group, mixer_meta_data->mixer_index, mixer_meta_data->mixer_sub_index, mixer_meta_data->inputs, mixer_meta_data->outputs);
}

/**
 * @brief Send a mixer_meta_data message
 * @param chan MAVLink channel to send the message
 *
 * @param mixer_group Access to different sets of mixers ie. onboard, failsafe, uavcan etc..
 * @param mixer_index Index of the mixer in the group
 * @param mixer_sub_index Index of the sub mixer in the mixer
 * @param inputs Mixer input connections
 * @param outputs Mixer output connections
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_mixer_meta_data_send(mavlink_channel_t chan, uint8_t mixer_group, uint8_t mixer_index, uint8_t mixer_sub_index, const uint16_t *inputs, const uint16_t *outputs)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MIXER_META_DATA_LEN];
    _mav_put_uint8_t(buf, 64, mixer_group);
    _mav_put_uint8_t(buf, 65, mixer_index);
    _mav_put_uint8_t(buf, 66, mixer_sub_index);
    _mav_put_uint16_t_array(buf, 0, inputs, 16);
    _mav_put_uint16_t_array(buf, 32, outputs, 16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MIXER_META_DATA, buf, MAVLINK_MSG_ID_MIXER_META_DATA_MIN_LEN, MAVLINK_MSG_ID_MIXER_META_DATA_LEN, MAVLINK_MSG_ID_MIXER_META_DATA_CRC);
#else
    mavlink_mixer_meta_data_t packet;
    packet.mixer_group = mixer_group;
    packet.mixer_index = mixer_index;
    packet.mixer_sub_index = mixer_sub_index;
    mav_array_memcpy(packet.inputs, inputs, sizeof(uint16_t)*16);
    mav_array_memcpy(packet.outputs, outputs, sizeof(uint16_t)*16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MIXER_META_DATA, (const char *)&packet, MAVLINK_MSG_ID_MIXER_META_DATA_MIN_LEN, MAVLINK_MSG_ID_MIXER_META_DATA_LEN, MAVLINK_MSG_ID_MIXER_META_DATA_CRC);
#endif
}

/**
 * @brief Send a mixer_meta_data message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_mixer_meta_data_send_struct(mavlink_channel_t chan, const mavlink_mixer_meta_data_t* mixer_meta_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_mixer_meta_data_send(chan, mixer_meta_data->mixer_group, mixer_meta_data->mixer_index, mixer_meta_data->mixer_sub_index, mixer_meta_data->inputs, mixer_meta_data->outputs);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MIXER_META_DATA, (const char *)mixer_meta_data, MAVLINK_MSG_ID_MIXER_META_DATA_MIN_LEN, MAVLINK_MSG_ID_MIXER_META_DATA_LEN, MAVLINK_MSG_ID_MIXER_META_DATA_CRC);
#endif
}

#if MAVLINK_MSG_ID_MIXER_META_DATA_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_mixer_meta_data_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t mixer_group, uint8_t mixer_index, uint8_t mixer_sub_index, const uint16_t *inputs, const uint16_t *outputs)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 64, mixer_group);
    _mav_put_uint8_t(buf, 65, mixer_index);
    _mav_put_uint8_t(buf, 66, mixer_sub_index);
    _mav_put_uint16_t_array(buf, 0, inputs, 16);
    _mav_put_uint16_t_array(buf, 32, outputs, 16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MIXER_META_DATA, buf, MAVLINK_MSG_ID_MIXER_META_DATA_MIN_LEN, MAVLINK_MSG_ID_MIXER_META_DATA_LEN, MAVLINK_MSG_ID_MIXER_META_DATA_CRC);
#else
    mavlink_mixer_meta_data_t *packet = (mavlink_mixer_meta_data_t *)msgbuf;
    packet->mixer_group = mixer_group;
    packet->mixer_index = mixer_index;
    packet->mixer_sub_index = mixer_sub_index;
    mav_array_memcpy(packet->inputs, inputs, sizeof(uint16_t)*16);
    mav_array_memcpy(packet->outputs, outputs, sizeof(uint16_t)*16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MIXER_META_DATA, (const char *)packet, MAVLINK_MSG_ID_MIXER_META_DATA_MIN_LEN, MAVLINK_MSG_ID_MIXER_META_DATA_LEN, MAVLINK_MSG_ID_MIXER_META_DATA_CRC);
#endif
}
#endif

#endif

// MESSAGE MIXER_META_DATA UNPACKING


/**
 * @brief Get field mixer_group from mixer_meta_data message
 *
 * @return Access to different sets of mixers ie. onboard, failsafe, uavcan etc..
 */
static inline uint8_t mavlink_msg_mixer_meta_data_get_mixer_group(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  64);
}

/**
 * @brief Get field mixer_index from mixer_meta_data message
 *
 * @return Index of the mixer in the group
 */
static inline uint8_t mavlink_msg_mixer_meta_data_get_mixer_index(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  65);
}

/**
 * @brief Get field mixer_sub_index from mixer_meta_data message
 *
 * @return Index of the sub mixer in the mixer
 */
static inline uint8_t mavlink_msg_mixer_meta_data_get_mixer_sub_index(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  66);
}

/**
 * @brief Get field inputs from mixer_meta_data message
 *
 * @return Mixer input connections
 */
static inline uint16_t mavlink_msg_mixer_meta_data_get_inputs(const mavlink_message_t* msg, uint16_t *inputs)
{
    return _MAV_RETURN_uint16_t_array(msg, inputs, 16,  0);
}

/**
 * @brief Get field outputs from mixer_meta_data message
 *
 * @return Mixer output connections
 */
static inline uint16_t mavlink_msg_mixer_meta_data_get_outputs(const mavlink_message_t* msg, uint16_t *outputs)
{
    return _MAV_RETURN_uint16_t_array(msg, outputs, 16,  32);
}

/**
 * @brief Decode a mixer_meta_data message into a struct
 *
 * @param msg The message to decode
 * @param mixer_meta_data C-struct to decode the message contents into
 */
static inline void mavlink_msg_mixer_meta_data_decode(const mavlink_message_t* msg, mavlink_mixer_meta_data_t* mixer_meta_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_mixer_meta_data_get_inputs(msg, mixer_meta_data->inputs);
    mavlink_msg_mixer_meta_data_get_outputs(msg, mixer_meta_data->outputs);
    mixer_meta_data->mixer_group = mavlink_msg_mixer_meta_data_get_mixer_group(msg);
    mixer_meta_data->mixer_index = mavlink_msg_mixer_meta_data_get_mixer_index(msg);
    mixer_meta_data->mixer_sub_index = mavlink_msg_mixer_meta_data_get_mixer_sub_index(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_MIXER_META_DATA_LEN? msg->len : MAVLINK_MSG_ID_MIXER_META_DATA_LEN;
        memset(mixer_meta_data, 0, MAVLINK_MSG_ID_MIXER_META_DATA_LEN);
    memcpy(mixer_meta_data, _MAV_PAYLOAD(msg), len);
#endif
}
