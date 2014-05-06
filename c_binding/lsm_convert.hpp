/*
 * Copyright (C) 2011-2013 Red Hat, Inc.
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * Author: tasleson
 */

#ifndef LSM_CONVERT_HPP
#define LSM_CONVERT_HPP

#include "lsm_datatypes.hpp"
#include "lsm_ipc.hpp"

/**
 * Converts an array of Values to a lsm_string_list
 * @param list      List represented as an vector of strings.
 * @return lsm_string_list pointer, NULL on error.
 */
lsm_string_list *value_to_string_list( Value &list);

/**
 * Converts a lsm_string_list to a Value
 * @param sl        String list to convert
 * @return Value
 */
Value string_list_to_value( lsm_string_list *sl);

/**
 * Converts a volume to a volume.
 * @param vol Value to convert.
 * @return lsm_volume *, else NULL on error
 */
lsm_volume * value_to_volume(Value &vol);

/**
 * Converts a lsm_volume * to a Value
 * @param vol lsm_volume to convert
 * @return Value
 */
Value volume_to_value(lsm_volume *vol);


/**
 * Converts a vector of volume values to an array
 * @param volume_values     Vector of values that represents volumes
 * @param volumes           An array of volume pointers
 * @param count             Number of volumes
 * @return LSM_ERR_OK on success, else error reason
 */
int value_array_to_volumes(Value &volume_values, lsm_volume **volumes[],
                            uint32_t *count);

/**
 * Converts a Value to a lsm_disk
 * @param disk  Value representing a disk
 * @return lsm_disk pointer, else NULL on error
 */
lsm_disk *value_to_disk(Value &disk);

/**
 * Converts a lsm_disk to a value
 * @param disk  lsm_disk to convert to value
 * @return Value
 */
Value disk_to_value(lsm_disk *disk);

/**
 * Converts a vector of disk values to an array.
 * @param disks     Vector of values that represents disks
 * @param disks     An array of disk pointers
 * @param count     Number of disks
 * @return LSM_ERR_OK on success, else error reason.
 */
int value_array_to_disks(Value &disk_values, lsm_disk **disks[],
                            uint32_t *count);

/**
 * Converts a value to lsm_initiator *
 * @param init  to convert
 * @return lsm_initiator *, else NULL on error.
 */
lsm_initiator *value_to_initiator(Value &init);

/**
 * Converts an lsm_initiator * to Value
 * @param init lsm_initiator to convert
 * @return Value
 */
Value initiator_to_value(lsm_initiator *init);

/**
 * Converts a value to a pool
 * @param pool To convert to lsm_pool *
 * @return lsm_pool *, else NULL on error.
 */
lsm_pool *value_to_pool(Value &pool);

/**
 * Converts a lsm_pool * to Value
 * @param pool Pool pointer to convert
 * @return Value
 */
Value pool_to_value(lsm_pool *pool);

/**
 * Converts a value to a system
 * @param system to convert to lsm_system *
 * @return lsm_system pointer, else NULL on error
 */
lsm_system *value_to_system(Value &system);

/**
 * Converts a lsm_system * to a Value
 * @param system pointer to convert to Value
 * @return Value
 */
Value system_to_value(lsm_system *system);

/**
 * Converts a Value to a lsm_access_group
 * @param group to convert to lsm_access_group*
 * @return lsm_access_group *, NULL on error
 */
lsm_access_group *value_to_access_group(Value &group);

/**
 * Converts a lsm_access_group to a Value
 * @param group     Group to convert
 * @return Value, null value type on error.
 */
Value access_group_to_value(lsm_access_group *group);

/**
 * Converts an access group list to an array of access group pointers
 * @param[in] group         Value representing a std::vector of access groups
 * @param[out] count         Number of items in the returned array.
 * @return NULL on memory allocation failure, else pointer to access group
 *          array.
 */
lsm_access_group **value_to_access_group_list( Value &group, uint32_t *count );

/**
 * Converts an array of lsm_access_group to Value(s)
 * @param group             Pointer to an array of lsm_access_group
 * @param count             Number of items in array.
 * @return std::vector of Values representing access groups
 */
Value access_group_list_to_value( lsm_access_group **group, uint32_t count);

/**
 * Converts a Value to a lsm_block_range
 * @param br        Value representing a block range
 * @return lsm_block_range *
 */
lsm_block_range *value_to_block_range(Value &br);

/**
 * Converts a lsm_block_range to a Value
 * @param br        lsm_block_range to convert
 * @return Value, null value type on error
 */
Value block_range_to_value(lsm_block_range *br);

/**
 * Converts a Value to an array of lsm_block_range
 * @param[in] brl           Value representing block range(s)
 * @param[out] count        Number of items in the resulting array
 * @return NULL on memory allocation failure, else array of lsm_block_range
 */
lsm_block_range **value_to_block_range_list(Value &brl,  uint32_t *count);

/**
 * Converts an array of lsm_block_range to Value
 * @param brl           An array of lsm_block_range
 * @param count         Number of items in input
 * @return Value
 */
Value block_range_list_to_value( lsm_block_range **brl, uint32_t count);

/**
 * Converts a value to a lsm_fs *
 * @param fs        Value representing a FS to be converted
 * @return lsm_fs pointer or NULL on error.
 */
lsm_fs *value_to_fs(Value &fs);

/**
 * Converts a lsm_fs pointer to a Value
 * @param fs        File system pointer to convert
 * @return Value
 */
Value fs_to_value(lsm_fs *fs);

/**
 * Converts a value to a lsm_ss *
 * @param ss        Value representing a snapshot to be converted
 * @return lsm_ss pointer or NULL on error.
 */
lsm_fs_ss *value_to_ss(Value &ss);

/**
 * Converts a lsm_ss pointer to a Value
 * @param ss        Snapshot pointer to convert
 * @return Value
 */
Value ss_to_value(lsm_fs_ss *ss);

/**
 * Converts a value to a lsm_nfs_export *
 * @param exp        Value representing a nfs export to be converted
 * @return lsm_nfs_export pointer or NULL on error.
 */
lsm_nfs_export *value_to_nfs_export(Value &exp);

/**
 * Converts a lsm_nfs_export pointer to a Value
 * @param exp        NFS export pointer to convert
 * @return Value
 */
Value nfs_export_to_value(lsm_nfs_export *exp);

/**
 * Converts a Value to a lsm_storage_capabilities
 * @param exp       Value representing a storage capabilities
 * @return lsm_storage_capabilities pointer or NULL on error
 */
lsm_storage_capabilities *value_to_capabilities(Value &exp);

/**
 * Converts a lsm_storage_capabilities to a value
 * @param cap       lsm_storage_capabilities to convert to value
 * @return Value
 */
Value capabilities_to_value(lsm_storage_capabilities *cap);

/**
 * Converts a value to optional data
 * @param op    Value to convert to optional data
 * @return lsm_optional_data pointer or NULL on error
 */
lsm_optional_data *value_to_optional_data(Value &op);

/**
 * Converts a lsm_optional_data pointer to a value
 * @param[in]   op  optional data pointer to convert
 * @return Value representing optional data
 */
Value optional_data_to_value(lsm_optional_data *op);

#endif